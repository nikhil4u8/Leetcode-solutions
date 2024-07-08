/*We need to evaluate an expressions string like these

"add(1,2)" returns 3
"subtract(6,2)" returns 4

Expressions can be nested too
"add(1,add(2,5))" returns 8

"add(subtract(9,1),add(2,5))" returns 15

"add(add(5,6),subtract(add(2,3),add(subtract(5,1),4)))" returns 8

expression = Number | add(expression, expression) | subtract(expression, expression)
*/
/*
Sol :
    - Maintain a stack & traverse string :
        1. If "add" comes then push it to stack & increment i pointer &
        process digits after add & push them too in stack
        2. If "subtract" comes then push it to stack & increment i pointer
        & process digits after subtract & add them to stack.
        3. If a ')' bracket comes meaning we've to process stack so pop out
        last 2 num from stack & operation name, if it's add then add both
        num & push result to stack & do same for subtract. Continue this
        until the whole stack is empty.
*/
public static int evaluateExpression(String s) {
    s = s.trim();
    Stack<String> stack = new Stack<>();
    int i =0;
    while (i <s.length()) {
        if (s.charAt(i) == 'a') {
            stack.push("add");
            // move three positions forward, length of add word
            i = i+3;
        } else if (s.charAt(i) == 's') {
            // move eight positions forward, length of subtract word or we could increment till we find a opening bracket
            stack.push("subtract"); // can be simplified to -1 and can be used multiplied with secodNum when popping the stack
            i = i+8;
        } else if (Character.isDigit(s.charAt(i))) {
            int num = s.charAt(i) - '0';
            while (i+1 < s.length() && Character.isDigit(s.charAt(i+1))) {
                num = num * 10 + s.charAt(++i) - '0';
            }
            stack.push(String.valueOf(num));
        } else if (s.charAt(i) == ')') {
            if (!stack.isEmpty()) {
                int secondNum = Integer.parseInt(stack.pop());
                int firstNum = Integer.parseInt(stack.pop());
                if (stack.pop().equals("add")) {
                    int current = firstNum + secondNum;
                    stack.push(String.valueOf(current));
                } else {
                    int current = firstNum - secondNum;
                    stack.push(String.valueOf(current));
                }

            }

        }
        // simply ignore if you find opening braces and increment as we have already pushed to the stack.
        i++;
    }
    return Integer.parseInt(stack.pop());
}