// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <iostream>
#include "boost/process.hpp"
#include "async++.h"
#include "iostream"
#include "string"
#include "memory"
#include "condition_variable"
#include "mutex"


class builder{
 public:
  builder();
  explicit builder(const size_t& ms_timeout);
  ~builder();

 private:
  std::function<void()>* build_func;
  std::function<void()>* install_func;
  std::function<void()>* pack_func;
  std::function<void()>* wait_for_timeout;
  std::atomic_bool timeout_flag;
  std::atomic_bool processes_completed;
  std::atomic_bool process_failed;
  std::unique_ptr<boost::process::child> current_process;
  std::string cmake_path;
  std::string config;
};







#endif // INCLUDE_HEADER_HPP_

