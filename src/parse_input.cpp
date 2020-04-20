#include "parse_input.hpp"

namespace act {

InputRollback::InputRollback(Input& input, size_t rollback)
    : _input(input)
    , _rollback(rollback)
    , _canceled(false)
{}

InputRollback::~InputRollback() {
    if (!_canceled) {
        _input._pos = _rollback;
    }
}

void InputRollback::cancel() {
    _canceled = true;
}

} // namespace act