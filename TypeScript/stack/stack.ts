//stack
class Stack<T>{
    private _stack:T[]=[];
    push(item:T){
        this._stack.push(item);
    }
    pop(){
        return this._stack.pop();
    }
    peek():T{
        return this._stack[this._stack.length-1];
    }
    isEmpty():boolean{
        return this._stack.length==0;
    }
    size():number{
        return this._stack.length;
    }
    clear(){
        this._stack=[];
    }
}
let stack=new Stack<number>();
stack.push(1);
stack.push(2);
stack.push(3);
stack.peek();