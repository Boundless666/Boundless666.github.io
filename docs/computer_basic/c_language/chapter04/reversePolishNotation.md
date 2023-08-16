```
while(next character is operator or operand & not EOF)
	if(number)
		Push it
	else if(operator)
		Pop operand
		do operator
		Pop operand
		Push result
	else if(newline)
		Pop and print top of stack
	else
		error
```

