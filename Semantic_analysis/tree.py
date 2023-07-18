from nltk.tree import *

# assign your output (generalied list of the syntax tree) to varaible text
# text = "[s [dp [d ['the']] [np [(]]] [vp [v [')']] [dp [d [the]] [np [cat]]]]]"
text="[program[program_body[function[Main_Structure[int][main[statement_list[statement[For_Statement[For_Parameters_2[For_Parameters_1[for_initializer_structure[for_initializer[int]][Semicolon]][for_condition[expression_statement[logical_or_expression[logical_a_exp[relational_exp[LT[relational_exp[additive_exp[multiplicative_exp[negation_exp[primary_exp[i]]]]]][additive_exp[multiplicative_exp[negation_exp[primary_exp[constant[10]]]]]]]]]]][Semicolon]]][for_update[assignment_statement[ASSIGNMENT[i][expression_statement[logical_or_expression[logical_a_exp[relational_exp[additive_exp[ADD[additive_exp[multiplicative_exp[negation_exp[primary_exp[i]]]]][multiplicative_exp[negation_exp[primary_exp[constant[1]]]]]]]]]]]]]]][compound_statement[statement_list[statement[assignment_statement[ASSIGNMENT[a][expression_statement[logical_or_expression[logical_a_exp[relational_exp[additive_exp[multiplicative_exp[negation_exp[primary_exp[constant[10]]]]]]]]]]]][Semicolon]][statement_list[statement[declaration_statement_structure[declaration_statement[int][var_list1[a]]][Semicolon]]][statement_list[statement[while_statement[expression_statement[logical_or_expression[logical_a_exp[relational_exp[LT[relational_exp[additive_exp[multiplicative_exp[negation_exp[primary_exp[j]]]]]][additive_exp[multiplicative_exp[negation_exp[primary_exp[constant[10]]]]]]]]]]][compound_statement[statement_list[statement[assignment_statement[ASSIGNMENT[j][expression_statement[logical_or_expression[logical_a_exp[relational_exp[additive_exp[ADD[additive_exp[multiplicative_exp[negation_exp[primary_exp[j]]]]][multiplicative_exp[negation_exp[primary_exp[constant[1]]]]]]]]]]]]][Semicolon]]]]]]]]]]]]]]]]]]"
text = text.replace("(", "ob")    #in the syntax tree, 'ob' will display in place of '('
text = text.replace(")", "cb")    #in the syntax tree, 'cb' will display in place of ')'
text = text.replace("[", "(")
text = text.replace("]", ")")


tree = Tree.fromstring(text)
tree.pretty_print(unicodelines=True, nodedist=3)