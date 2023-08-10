#include "kind.h"

#include <iostream>

namespace alfc {

std::ostream& operator<<(std::ostream& o, Kind k)
{
  switch (k)
  {
    case Kind::NONE: o << "NONE"; break;
    case Kind::TYPE: o << "TYPE"; break;
    case Kind::FUNCTION_TYPE: o << "FUNCTION_TYPE"; break;
    case Kind::REQUIRES_TYPE: o << "REQUIRES_TYPE"; break;
    case Kind::PROOF_TYPE: o << "PROOF_TYPE"; break;
    case Kind::ABSTRACT_TYPE: o << "ABSTRACT_TYPE"; break;
    case Kind::BOOL_TYPE: o << "BOOL_TYPE"; break;
    case Kind::QUOTE_TYPE: o << "QUOTE_TYPE"; break;
    // terms
    case Kind::APPLY: o << "APPLY"; break;
    case Kind::LAMBDA: o << "LAMBDA"; break;
    case Kind::CONST: o << "CONST"; break;
    case Kind::PROGRAM_CONST: o << "PROGRAM_CONST"; break;
    case Kind::PROOF_RULE: o << "PROOF_RULE"; break;
    case Kind::VARIABLE: o << "VARIABLE"; break;
    case Kind::VARIABLE_LIST: o << "VARIABLE_LIST"; break;
    case Kind::QUOTE: o << "QUOTE"; break;
    case Kind::NIL: o << "NIL"; break;
    case Kind::PROGRAM: o << "PROGRAM"; break;
    case Kind::PAIR: o << "PAIR"; break;
    // literals
    case Kind::BOOLEAN: o << "BOOLEAN"; break;
    case Kind::NUMERAL: o << "NUMERAL"; break;
    case Kind::DECIMAL: o << "DECIMAL"; break;
    case Kind::HEXADECIMAL: o << "HEXADECIMAL"; break;
    case Kind::BINARY: o << "BINARY"; break;
    case Kind::STRING: o << "STRING"; break;
    // operations on literals
    case Kind::EVAL_ADD: o << "EVAL_ADD"; break;
    case Kind::EVAL_NEG: o << "EVAL_NEG"; break;
    case Kind::EVAL_MUL: o << "EVAL_MUL"; break;
    case Kind::EVAL_INT_DIV: o << "EVAL_INT_DIV"; break;
    case Kind::EVAL_RAT_DIV: o << "EVAL_RAT_DIV"; break;
    case Kind::EVAL_IS_NEG: o << "EVAL_IS_NEG"; break;
    case Kind::EVAL_IS_ZERO: o << "EVAL_IS_ZERO"; break;
    case Kind::EVAL_TO_INT: o << "EVAL_TO_INT"; break;
    case Kind::EVAL_TO_RAT: o << "EVAL_TO_RAT"; break;
    default: o << "UnknownKind(" << unsigned(k) << ")"; break;
  }
  return o;
}

std::string kindToTerm(Kind k)
{
  std::stringstream ss;
  switch (k)
  {
    case Kind::TYPE: ss << "Type"; break;
    case Kind::FUNCTION_TYPE: ss << "->"; break;
    case Kind::PROOF_TYPE: ss << "Proof"; break;
    case Kind::ABSTRACT_TYPE: ss << "?"; break;
    case Kind::BOOL_TYPE: ss << "Bool"; break;
    case Kind::QUOTE_TYPE: ss << "Quote"; break;
    case Kind::REQUIRES_TYPE: ss << "Requires"; break;
    // terms
    case Kind::APPLY: ss << "@"; break;
    case Kind::LAMBDA: ss << "lambda"; break;
    case Kind::QUOTE: ss << "quote"; break;
    case Kind::PROGRAM: ss << "program"; break;
    // operations on literals
    default:
      if (isLiteralOp(k))
      {
        ss << "eval.";
        switch (k)
        {
        case Kind::EVAL_ADD: ss << "add";break;
        case Kind::EVAL_NEG: ss << "neg";break;
        case Kind::EVAL_MUL: ss << "mul";break;
        case Kind::EVAL_INT_DIV: ss << "zdiv";break;
        case Kind::EVAL_RAT_DIV: ss << "qdiv";break;
        case Kind::EVAL_IS_NEG: ss << "is_neg";break;
        case Kind::EVAL_IS_ZERO: ss << "is_zero";break;
        case Kind::EVAL_TO_INT: ss << "to_z";break;
        case Kind::EVAL_TO_RAT: ss << "to_q";break;
        default:ss << "[" << k << "]";break;
        }
      }
      else
      {
        ss << "[" << k << "]";
      }
      break;
  }
  return ss.str();
}

bool isSymbol(Kind k)
{
  switch(k)
  {
    case Kind::CONST:
    case Kind::PROGRAM_CONST:
    case Kind::PROOF_RULE:
    case Kind::VARIABLE: return true; break;
    default: break;
  }
  return false;
}
bool isLiteral(Kind k)
{
  switch(k)
  {
    case Kind::BOOLEAN:
    case Kind::NUMERAL:
    case Kind::DECIMAL:
    case Kind::HEXADECIMAL:
    case Kind::BINARY:
    case Kind::STRING: return true; break;
    default: break;
  }
  return false;
}
bool isLiteralOp(Kind k)
{
  switch(k)
  {
    case Kind::EVAL_ADD:
    case Kind::EVAL_NEG:
    case Kind::EVAL_MUL:
    case Kind::EVAL_INT_DIV:
    case Kind::EVAL_RAT_DIV:
    case Kind::EVAL_IS_NEG:
    case Kind::EVAL_IS_ZERO:
    case Kind::EVAL_TO_INT:
    case Kind::EVAL_TO_RAT: return true; break;
    default: break;
  }
  return false;
}

}  // namespace alfc
