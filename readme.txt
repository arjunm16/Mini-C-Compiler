Group Members
Dhruv Saxena : 2019B4A71369H
Arjun Muthiah : 2019B3A70374H

## Instructions to run the code
1) Compile the lexical Code using the following command
``` flex lexer.l 
    cc lex.yy.cc```

Run the code using the following command
``` ./a.out < <input_file> ```

2) Compile the remaining parts of the code using the following command
``` flex lexer.l
    bison -d --yacc parser.y
    cc y.tab.c```

Run the code using the following command
``` ./a.out < <input_file> ```