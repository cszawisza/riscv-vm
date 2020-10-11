#include <assert.h>
#include <string.h>

#include "../riscv_emu/riscv_private.h"

#include "ir.h"


static struct ir_inst_t *ir_alloc(struct ir_block_t *block) {
  assert(block);
  struct ir_inst_t *i = block->inst + (block->head++);
  assert((const void*)(i+1) < block->end);
  memset(i, 0, sizeof(struct ir_inst_t));
  return i;
}

struct ir_block_t *ir_init(void *start, void *end) {
  memset(start, 0, sizeof(struct ir_block_t));
  struct ir_block_t *block = (struct ir_block_t *)start;
  block->end = end;
  return block;
}

struct ir_inst_t *ir_imm(struct ir_block_t *block, int32_t imm) {
  assert(block);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_imm;
  i->imm = imm;
  return i;
}

struct ir_inst_t *ir_ld_reg(struct ir_block_t *block, int32_t offset) {
  assert(block);
  struct ir_inst_t *i = block->inst + (block->head++);
  i->op = inst_ld_reg;
  i->offset = offset;
  return i;
}

struct ir_inst_t *ir_st_reg(struct ir_block_t *block, int32_t offset, struct ir_inst_t *val) {
  assert(block && val);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_st_reg;
  i->offset = offset;
  i->value = val;
  val->parent = i;
  return i;
}

struct ir_inst_t *ir_st_pc(struct ir_block_t *block, struct ir_inst_t *val) {
  assert(block && val);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_st_pc;
  i->value = val;
  val->parent = i;
  return i;
}

struct ir_inst_t *ir_add(struct ir_block_t *block, struct ir_inst_t *lhs, struct ir_inst_t *rhs) {
  assert(block && lhs && rhs);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_add;
  i->lhs = lhs;
  i->rhs = rhs;
  lhs->parent = i;
  rhs->parent = i;
  return i;
}

struct ir_inst_t *ir_sub(struct ir_block_t *block, struct ir_inst_t *lhs, struct ir_inst_t *rhs) {
  assert(block && lhs && rhs);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_sub;
  i->lhs = lhs;
  i->rhs = rhs;
  lhs->parent = i;
  rhs->parent = i;
  return i;
}

struct ir_inst_t *ir_and(struct ir_block_t *block, struct ir_inst_t *lhs, struct ir_inst_t *rhs) {
  assert(block && lhs && rhs);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_and;
  i->lhs = lhs;
  i->rhs = rhs;
  lhs->parent = i;
  rhs->parent = i;
  return i;
}

struct ir_inst_t *ir_or(struct ir_block_t *block, struct ir_inst_t *lhs, struct ir_inst_t *rhs) {
  assert(block && lhs && rhs);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_or;
  i->lhs = lhs;
  i->rhs = rhs;
  lhs->parent = i;
  rhs->parent = i;
  return i;
}

struct ir_inst_t *ir_xor(struct ir_block_t *block, struct ir_inst_t *lhs, struct ir_inst_t *rhs) {
  assert(block && lhs && rhs);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_xor;
  i->lhs = lhs;
  i->rhs = rhs;
  lhs->parent = i;
  rhs->parent = i;
  return i;
}

struct ir_inst_t *ir_shr(struct ir_block_t *block, struct ir_inst_t *lhs, struct ir_inst_t *rhs) {
  assert(block && lhs && rhs);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_shr;
  i->lhs = lhs;
  i->rhs = rhs;
  lhs->parent = i;
  rhs->parent = i;
  return i;
}

struct ir_inst_t *ir_sar(struct ir_block_t *block, struct ir_inst_t *lhs, struct ir_inst_t *rhs) {
  assert(block && lhs && rhs);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_sar;
  i->lhs = lhs;
  i->rhs = rhs;
  lhs->parent = i;
  rhs->parent = i;
  return i;
}

struct ir_inst_t *ir_shl(struct ir_block_t *block, struct ir_inst_t *lhs, struct ir_inst_t *rhs) {
  assert(block && lhs && rhs);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_shl;
  i->lhs = lhs;
  i->rhs = rhs;
  lhs->parent = i;
  rhs->parent = i;
  return i;
}

struct ir_inst_t *ir_mul(struct ir_block_t *block, struct ir_inst_t *lhs, struct ir_inst_t *rhs) {
  assert(block && lhs && rhs);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_mul;
  i->lhs = lhs;
  i->rhs = rhs;
  lhs->parent = i;
  rhs->parent = i;
  return i;
}

struct ir_inst_t *ir_mulh(struct ir_block_t *block, struct ir_inst_t *lhs, struct ir_inst_t *rhs) {
  assert(block && lhs && rhs);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_mulh;
  i->lhs = lhs;
  i->rhs = rhs;
  lhs->parent = i;
  rhs->parent = i;
  return i;
}

struct ir_inst_t *ir_mulhsu(struct ir_block_t *block, struct ir_inst_t *lhs, struct ir_inst_t *rhs) {
  assert(block && lhs && rhs);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_mulhsu;
  i->lhs = lhs;
  i->rhs = rhs;
  lhs->parent = i;
  rhs->parent = i;
  return i;
}

struct ir_inst_t *ir_mulhu(struct ir_block_t *block, struct ir_inst_t *lhs, struct ir_inst_t *rhs) {
  assert(block && lhs && rhs);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_mulhu;
  i->lhs = lhs;
  i->rhs = rhs;
  lhs->parent = i;
  rhs->parent = i;
  return i;
}

struct ir_inst_t *ir_div(struct ir_block_t *block, struct ir_inst_t *lhs, struct ir_inst_t *rhs) {
  assert(block && lhs && rhs);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_div;
  i->lhs = lhs;
  i->rhs = rhs;
  lhs->parent = i;
  rhs->parent = i;
  return i;
}

struct ir_inst_t *ir_divu(struct ir_block_t *block, struct ir_inst_t *lhs, struct ir_inst_t *rhs) {
  assert(block && lhs && rhs);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_divu;
  i->lhs = lhs;
  i->rhs = rhs;
  lhs->parent = i;
  rhs->parent = i;
  return i;
}

struct ir_inst_t *ir_rem(struct ir_block_t *block, struct ir_inst_t *lhs, struct ir_inst_t *rhs) {
  assert(block && lhs && rhs);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_rem;
  i->lhs = lhs;
  i->rhs = rhs;
  lhs->parent = i;
  rhs->parent = i;
  return i;
}

struct ir_inst_t *ir_remu(struct ir_block_t *block, struct ir_inst_t *lhs, struct ir_inst_t *rhs) {
  assert(block && lhs && rhs);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_remu;
  i->lhs = lhs;
  i->rhs = rhs;
  lhs->parent = i;
  rhs->parent = i;
  return i;
}

struct ir_inst_t *ir_sb(struct ir_block_t *block, struct ir_inst_t *addr, struct ir_inst_t *val) {
  assert(block && addr && val);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_sb;
  i->value = val;
  i->addr = addr;
  addr->parent = i;
  val->parent = i;
  return i;
}

struct ir_inst_t *ir_sh(struct ir_block_t *block, struct ir_inst_t *addr, struct ir_inst_t *val) {
  assert(block && addr && val);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_sh;
  i->value = val;
  i->addr = addr;
  addr->parent = i;
  val->parent = i;
  return i;
}

struct ir_inst_t *ir_sw(struct ir_block_t *block, struct ir_inst_t *addr, struct ir_inst_t *val) {
  assert(block && addr && val);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_sw;
  i->value = val;
  i->addr = addr;
  addr->parent = i;
  val->parent = i;
  return i;
}

struct ir_inst_t *ir_lb(struct ir_block_t *block, struct ir_inst_t *addr) {
  assert(block && addr);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_lb;
  i->addr = addr;
  addr->parent = i;
  return i;
}

struct ir_inst_t *ir_lh(struct ir_block_t *block, struct ir_inst_t *addr) {
  assert(block && addr);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_lh;
  i->addr = addr;
  addr->parent = i;
  return i;
}

struct ir_inst_t *ir_lw(struct ir_block_t *block, struct ir_inst_t *addr) {
  assert(block && addr);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_lw;
  i->addr = addr;
  addr->parent = i;
  return i;
}

struct ir_inst_t *ir_lbu(struct ir_block_t *block, struct ir_inst_t *addr) {
  assert(block && addr);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_lbu;
  i->addr = addr;
  addr->parent = i;
  return i;
}

struct ir_inst_t *ir_lhu(struct ir_block_t *block, struct ir_inst_t *addr) {
  assert(block && addr);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_lhu;
  i->addr = addr;
  addr->parent = i;
  return i;
}

struct ir_inst_t *ir_ecall(struct ir_block_t *block) {
  assert(block);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_ecall;
  return i;
}

struct ir_inst_t *ir_ebreak(struct ir_block_t *block) {
  assert(block);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_ebreak;
  return i;
}

struct ir_inst_t *ir_eq(struct ir_block_t *block, struct ir_inst_t *lhs, struct ir_inst_t *rhs) {
  assert(block && lhs && rhs);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_eq;
  i->lhs = lhs;
  i->rhs = rhs;
  lhs->parent = i;
  rhs->parent = i;
  return i;
}

struct ir_inst_t *ir_neq(struct ir_block_t *block, struct ir_inst_t *lhs, struct ir_inst_t *rhs) {
  assert(block && lhs && rhs);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_neq;
  i->lhs = lhs;
  i->rhs = rhs;
  lhs->parent = i;
  rhs->parent = i;
  return i;
}

struct ir_inst_t *ir_lt(struct ir_block_t *block, struct ir_inst_t *lhs, struct ir_inst_t *rhs) {
  assert(block && lhs && rhs);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_lt;
  i->lhs = lhs;
  i->rhs = rhs;
  lhs->parent = i;
  rhs->parent = i;
  return i;
}

struct ir_inst_t *ir_ge(struct ir_block_t *block, struct ir_inst_t *lhs, struct ir_inst_t *rhs) {
  assert(block && lhs && rhs);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_ge;
  i->lhs = lhs;
  i->rhs = rhs;
  lhs->parent = i;
  rhs->parent = i;
  return i;
}

struct ir_inst_t *ir_ltu(struct ir_block_t *block, struct ir_inst_t *lhs, struct ir_inst_t *rhs) {
  assert(block && lhs && rhs);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_ltu;
  i->lhs = lhs;
  i->rhs = rhs;
  lhs->parent = i;
  rhs->parent = i;
  return i;
}

struct ir_inst_t *ir_geu(struct ir_block_t *block, struct ir_inst_t *lhs, struct ir_inst_t *rhs) {
  assert(block && lhs && rhs);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_geu;
  i->lhs = lhs;
  i->rhs = rhs;
  lhs->parent = i;
  rhs->parent = i;
  return i;
}

struct ir_inst_t *ir_branch(struct ir_block_t *block,
                            struct ir_inst_t *cond,
                            struct ir_inst_t *taken,
                            struct ir_inst_t *not_taken) {
  assert(block && cond && taken && not_taken);
  struct ir_inst_t *i = ir_alloc(block);
  i->op = inst_branch;
  i->cond = cond;
  i->lhs = taken;
  i->rhs = not_taken;
  cond->parent = i;
  taken->parent = i;
  not_taken->parent = i;
  return i;
}

static int32_t eval(struct riscv_t *rv, const struct ir_inst_t *i) {
  switch (i->op) {
  case inst_imm:
    return i->imm;
  case inst_ld_reg:
    return (int32_t)(rv->X[i->offset]);
  case inst_st_reg:
    rv->X[i->offset] = eval(rv, i->value);
    break;
  case inst_st_pc:
    rv->PC = eval(rv, i->value);
    break;
  case inst_branch:
    rv->PC = eval(rv, i->cond) ? eval(rv, i->lhs) : eval(rv, i->rhs);
    break;
  case inst_add:
    return eval(rv, i->lhs) + eval(rv, i->rhs);
  case inst_sub:
    return eval(rv, i->lhs) - eval(rv, i->rhs);
  case inst_and:
    return eval(rv, i->lhs) & eval(rv, i->rhs);
  case inst_or:
    return eval(rv, i->lhs) | eval(rv, i->rhs);
  case inst_xor:
    return eval(rv, i->lhs) ^ eval(rv, i->rhs);
  case inst_shr:
    return (uint32_t)eval(rv, i->lhs) >> (uint32_t)eval(rv, i->rhs);
  case inst_sar:
    return eval(rv, i->lhs) >> eval(rv, i->rhs);
  case inst_shl:
    return (uint32_t)eval(rv, i->lhs) << (uint32_t)eval(rv, i->rhs);

  case inst_mul:
    return (int32_t)eval(rv, i->lhs) * (int32_t)eval(rv, i->rhs);
  case inst_mulh:
  {
    const int64_t a = (int64_t)eval(rv, i->lhs);
    const int64_t b = (int64_t)eval(rv, i->rhs);
    return ((uint64_t)(a * b)) >> 32;
  }
  case inst_mulhsu:
  {
    const int64_t a = (int64_t)eval(rv, i->lhs);
    const uint64_t b = (uint32_t)eval(rv, i->rhs);
    return ((uint64_t)(a * b)) >> 32;
  }
  case inst_mulhu:
  {
    const uint64_t a = ((uint32_t)eval(rv, i->lhs));
    const uint64_t b = ((uint32_t)eval(rv, i->rhs));
    return (a * b) >> 32;
  }
  case inst_div:
  {
    const int32_t dividend = eval(rv, i->lhs);
    const int32_t divisor = eval(rv, i->rhs);
    if (divisor == 0) {
      return ~0u;
    }
    else if (divisor == -1 && dividend == 0x80000000u) {
      return dividend;
    }
    else {
      return dividend / divisor;
    }
  }
  case inst_divu:
  {
    const uint32_t dividend = eval(rv, i->lhs);
    const uint32_t divisor = eval(rv, i->rhs);
    return (divisor == 0) ? ~0u : (dividend / divisor);
  }
  case inst_rem:
  {
    const int32_t dividend = eval(rv, i->lhs);
    const int32_t divisor = eval(rv, i->rhs);
    if (divisor == 0) {
      return dividend;
    }
    else if (divisor == -1 && dividend == 0x80000000u) {
      return 0;
    }
    else {
      return dividend % divisor;
    }
  }
  case inst_remu:
  {
    const uint32_t dividend = eval(rv, i->lhs);
    const uint32_t divisor = eval(rv, i->rhs);
    return (divisor == 0) ? dividend : (dividend % divisor);
  }
  case inst_eq:
    return eval(rv, i->lhs) == eval(rv, i->rhs);
  case inst_neq:
    return eval(rv, i->lhs) != eval(rv, i->rhs);
  case inst_lt:
    return eval(rv, i->lhs) < eval(rv, i->rhs);
  case inst_ge:
    return eval(rv, i->lhs) >= eval(rv, i->rhs);
  case inst_ltu:
    return (uint32_t)eval(rv, i->lhs) < (uint32_t)eval(rv, i->rhs);
  case inst_geu:
    return (uint32_t)eval(rv, i->lhs) >= (uint32_t)eval(rv, i->rhs);
  case inst_sb:
    rv->io.mem_write_b(rv, (uint32_t)eval(rv, i->addr), eval(rv, i->value));
    break;
  case inst_sh:
    rv->io.mem_write_s(rv, (uint32_t)eval(rv, i->addr), eval(rv, i->value));
    break;
  case inst_sw:
    rv->io.mem_write_w(rv, (uint32_t)eval(rv, i->addr), eval(rv, i->value));
    break;
  case inst_lb:
    return (int8_t)rv->io.mem_read_b(rv, (uint32_t)eval(rv, i->addr));
  case inst_lh:
    return (int16_t)rv->io.mem_read_s(rv, (uint32_t)eval(rv, i->addr));
  case inst_lw:
    return (int32_t)rv->io.mem_read_w(rv, (uint32_t)eval(rv, i->addr));
  case inst_lbu:
    return (uint8_t)rv->io.mem_read_b(rv, (uint32_t)eval(rv, i->addr));
  case inst_lhu:
    return (uint16_t)rv->io.mem_read_s(rv, (uint32_t)eval(rv, i->addr));
  case inst_ecall:
    rv->io.on_ecall(rv, 0, 0);
    break;
  case inst_ebreak:
    rv->io.on_ebreak(rv, 0, 0);
    break;
  default:
    assert(!"unreachable");
  }
  // this should be a root instruction
  assert(i->parent == NULL);
  return 0;
}

void ir_eval(struct ir_block_t *block, struct riscv_t *rv) {
  for (int i = 0; i < block->head; ++i) {
    const struct ir_inst_t *inst = block->inst + i;
    if (inst->parent != NULL) {
      continue;
    }
    eval(rv, inst);
  }
}
