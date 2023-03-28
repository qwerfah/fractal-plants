#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <iostream>

class BadStream : std::exception
{
  public:
    BadStream(const std::string &message) : message(message) {}

    const char *what() const throw()
    {
        return message.c_str();
    }

  private:
    std::string message;
};

class WrongObjectType : std::exception
{
  public:
    WrongObjectType(const std::string &message, const std::string &type)
        : message(message), wrongType(type) {}

    const char *what() const throw()
    {
        return message.c_str();
    }

    std::string getType()
    {
        return wrongType;
    }

  private:
    std::string message;
    std::string wrongType;
};

class FactoryWrongValue : std::exception
{
  public:
    FactoryWrongValue(const std::string &message, size_t id)
        : message(message), id(id) {}

    const char *what() const throw()
    {
        return message.c_str();
    }

    size_t getId()
    {
        return id;
    }

  private:
    std::string message;
    size_t id;
};

class BadPtr : std::exception
{
  public:
    BadPtr(const std::string &message) : message(message) {}

    const char *what() const throw()
    {
        return message.c_str();
    }

  private:
    std::string message;
};

class BadCast : std::exception
{
  public:
    BadCast(const std::string &message) : message(message) {}

    const char *what() const throw()
    {
        return message.c_str();
    }

  private:
    std::string message;
};

class AmbigiousChoice : std::exception
{
  public:
    AmbigiousChoice(const std::string &message) : message(message) {}

    const char *what() const throw()
    {
        return message.c_str();
    }

  private:
    std::string message;
};

class CorruptedData : std::exception
{
  public:
    CorruptedData(const std::string &message) : message(message) {}

    const char *what() const throw()
    {
        return message.c_str();
    }

  private:
    std::string message;
};

class NotImplemented : std::exception
{
  public:
    NotImplemented(const std::string &message) : message(message) {}

    const char *what() const throw()
    {
        return message.c_str();
    }

  private:
    std::string message;
};

class NotFound : std::exception
{
public:
  NotFound(const std::string &message) : message(message) {}

  const char *what() const throw()
  {
      return message.c_str();
  }

private:
  std::string message;
};

class OutdatedCommand : std::exception
{
  public:
    OutdatedCommand(const std::string &message) : message(message) {}

    const char *what() const throw()
    {
        return message.c_str();
    }

  private:
    std::string message;
};

class OutOfDimension : std::exception
{
  public:
    OutOfDimension(const std::string &message, size_t realDimension,
                   size_t requiredDimension)
        : message(message), realDimension(realDimension),
          requiredDimension(requiredDimension) {}

    const char *what() const throw()
    {
        return message.c_str();
    }

    size_t getRealDimenstion() const
    {
        return realDimension;
    }

    size_t getRequiredDimension() const
    {
        return requiredDimension;
    }

  private:
    std::string message;
    size_t realDimension;
    size_t requiredDimension;
};

class BadDLLLibrary : std::exception
{
  public:
    BadDLLLibrary(const std::string &message) : message(message) {}

    const char *what() const throw()
    {
        return message.c_str();
    }

  private:
    std::string message;
};

class BadFunction : std::exception
{
  public:
    BadFunction(const std::string &message) : message(message) {}

    const char *what() const throw()
    {
        return message.c_str();
    }

  private:
    std::string message;
};

class BadParameters : std::exception
{
  public:
    BadParameters(const std::string &message) : message(message) {}

    const char *what() const throw()
    {
        return message.c_str();
    }

  private:
    std::string message;
};

class EmptyRulesList : std::exception
{
  public:
    EmptyRulesList(const std::string &message) : message(message) {}

    const char *what() const throw()
    {
        return message.c_str();
    }

  private:
    std::string message;
};

class TriangulationNotEnoughData : std::exception
{
  public:
    TriangulationNotEnoughData(const std::string &message, size_t pts) : message(message), pointNumber(pts) {}

    const char *what() const throw()
    {
        return message.c_str();
    }

    size_t getPointNumber() const
    {
        return pointNumber;
    }

  private:
    std::string message;
    size_t pointNumber;
};

#endif // EXCEPTIONS_H
