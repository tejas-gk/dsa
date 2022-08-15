//stack
var Stack = /** @class */ (function () {
    function Stack() {
        this._stack = [];
    }
    Stack.prototype.push = function (item) {
        this._stack.push(item);
    };
    Stack.prototype.pop = function () {
        return this._stack.pop();
    };
    Stack.prototype.peek = function () {
        return this._stack[this._stack.length - 1];
    };
    Stack.prototype.isEmpty = function () {
        return this._stack.length == 0;
    };
    Stack.prototype.size = function () {
        return this._stack.length;
    };
    Stack.prototype.clear = function () {
        this._stack = [];
    };
    return Stack;
}());
var stack = new Stack();
stack.push(1);
stack.push(2);
stack.push(3);
stack.peek();
