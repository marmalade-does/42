FILE='inter.c'
ASSIGN='inter'

bash .system/auto_correc_program.sh $FILE $ASSIGN "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN "ddf6vewg64f" "gtwthgdwthdwfteewhrtag6h4ffdhsd"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN "rien" "cette phrase ne cache rien"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN "Oupsi" "Oups"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN "Manger pour vivre" "Vivre pour manger"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN 
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN "Too" "Many" "Arguments"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

touch .system/grading/passed;
