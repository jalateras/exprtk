#include <iostream>
#include <node.h>
#include <v8.h>
#include "exprtk.hpp"

using namespace std;
using namespace v8;
using namespace exprtk;

Handle<Value> Evaluate(const Arguments& args) {
  HandleScope scope;

  if (args.Length() < 1 && !args[0]->IsString()) {
    ThrowException(Exception::TypeError(String::New("You must supply an expression as a string")));
    return scope.Close(Undefined());
  }

  v8::String::Utf8Value arg0(args[0]->ToString());
  std::string expression_string = std::string(*arg0);

  expression<double> expression;
  parser<double> parser;
  parser.compile(expression_string, expression);
  double result;
  for (size_t i = 0; i < 1000; i++) {
    result = expression.value();
  }

  return scope.Close(Number::New(result));
}

void init(Handle<Object> exports) {
  exports->Set(String::NewSymbol("evaluate"),
      FunctionTemplate::New(Evaluate)->GetFunction());
}

NODE_MODULE(formula, init)