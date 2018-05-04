#ifndef QUEUE_EXCEPTIONS_HPP
#define QUEUE_EXCEPTIONS_HPP

#include <string>

class Exception{
public:
  Exception(std::string s) : msg(s) {}
  std::string getmsg() const { return msg;}

private:
  std::string msg;
};

class QueueEmpty : public Exception {
public:
  QueueEmpty(std::string s) : Exception(s) {}
};

#endif /* QUEUE_EXCEPTIONS_HPP */
