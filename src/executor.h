/******************************************************************************
 * This file is part of the alfc project.
 *
 * Copyright (c) 2023-2024 by the authors listed in the file AUTHORS
 * in the top-level source directory and their institutional affiliations.
 * All rights reserved.  See the file COPYING in the top-level source
 * directory for licensing information.
 ******************************************************************************/

#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <map>
#include <set>
#include <sstream>
#include <string>

#include "plugin.h"

namespace alfc {

/**
 * The executor class, which calls compiled C++ code generated by the compiler
 * plugin for more efficient execution of type checking and side condition
 * evaluation.
 */
class Executor : public Plugin
{
  friend class TypeChecker;
public:
  Executor(State& s);
  ~Executor();
  /** Print compiled files (for --show-config) */
  static std::string showCompiledFiles();
  /** Initialize. */
  void initialize() override;
  /** Has evaluation. */
  bool hasEvaluation(ExprValue* e) override;
  /** Get type. */
  Expr getType(ExprValue* hdType,
               const std::vector<ExprValue*>& args,
               std::ostream* out) override;
  /** Evaluate. */
  Expr evaluate(ExprValue* e, Ctx& ctx) override;
  /** Evaluate program */
  Expr evaluateProgram(ExprValue* prog, const std::vector<ExprValue*>& args, Ctx& ctx) override;
private:
  /** Reference to the state */
  State& d_state;
  /** Reference to the type checker */
  TypeChecker& d_tc;
  /** The null expression */
  Expr d_null;
  /** Compiled version */
  ExprValue* evaluateProgramInternal(const std::vector<ExprValue*>& args, Ctx& ctx);
};

}  // namespace alfc

#endif /* EXECUTOR_H */
