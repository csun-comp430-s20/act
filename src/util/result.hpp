#pragma once

#include <variant>
#include <optional>

// Simplified/better interface over std::variant<T, E>.
// Holds either a T or some kind of error E.
template <typename T, typename E>
class Result {
    std::variant<T, E> _value;

    public:
        static Result<T,E> ok(T t) {
            return Result(std::move(t));
        }

        Result(T t)
            : _value(std::move(t))
        {}

        Result(E e)
            : _value(std::move(e))
        {}

        explicit operator bool() const {
            return std::holds_alternative<T>(_value);
        }
        
        T const& value() const {
            return std::get<T>(_value);
        }

        E const& error() const {
            return std::get<E>(_value);
        }
        
        T into_value() {
            return std::get<T>(std::move(_value));
        }

        std::unique_ptr<T> into_ptr() {
            return std::make_unique<T>(into_value());
        }
};

// When there's no value, only a possible error.
template <typename E>
class Result<void, E> {
    std::optional<E> _error;

    public:
        static Result<void,E> ok() {
            return Result(std::monostate{});
        }

        Result(std::monostate)
            : _error(std::nullopt)
        {}

        Result(E e)
            : _error(std::move(e))
        {}

        explicit operator bool() const {
            return !_error.has_value();
        }
        
        E const& error() const {
            return _error.value();
        }
};

template <typename E>
using Result_ = Result<void, E>;

// "auto a = ...;" where ... is a Result<T,E>.
// On failure, returns the E.
#define TRY(a, ...) auto a##__ = __VA_ARGS__; if (!a##__) { return a##__.error(); } auto a = a##__.into_value();

// TRY when there's no value to keep.
#define TRY_(...) { auto try__ = __VA_ARGS__; if (!try__) { return try__.error(); }}
