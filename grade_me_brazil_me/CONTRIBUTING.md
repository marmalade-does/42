# How to contribute by adding more exercices:

Você pode adicionar um novo exercicio simplismente criando uma pasta para o exercicio em `.subjects`.

👉 42_EXAM dectecta os novos exercicios automaticamente, então nenhuma mudança precisa ser feita no programa.

To add an exercise you have to create a folder with the name of the exercise in its respective level (browse the .subjects folder to understand)
- Para adicionar um exercicio, você tem que criar a pasta com o nome do exercicio em seu respectivel level
(Veja a pasta .subjects para entender) 

--------
 
-🔖 Para o exercicio estar completo, você deve adicionar:

- Um subject nomeado `subject.en.txt` em uma pasta `attachment` (você pode adicionar outros arquivos que serão dados ao estudante durante o exercicio)
- O código do exercicio completo (exemplo : fprime.c) 
⚠️ WARNING: O exercicio deve estar perfeito, pois ele será usado para o 42_exam corrrigir o level corretamente.
- O arquivo de correção `tester.sh`, que permite você enviar os inputs que quiser.

``` 
fprime
 |
 |__attachment
 |    |__subjects.en.txt
 |    |__(Outros arquivos para o exercicio)
 |
 |__fprime.c (O exercicio deve estar perfeito)
 |
 |__main.c (Se o exercicio for uma função ao invés de um programa)
 |
 |__tester.sh (detalhes abaixo)

``` 


🔎 Aqui estão dois tipos de `tester.sh`.
Você deve usar a primeira se o exercicio for um  **programa**, e por isso não precisa de uma main.

Você deve usar a segunda opção se for uma **função**, e por isso precisa de uma main (você tem que prover a main)

Esse é o primeiro tester.sh *(PROGRAM EXERCISE)*:

``` 
FILE='fprime.c'                                                  # Nome do exercicio
ASSIGN='fprime'                                                  # Nome da pasta

bash .system/auto_correc_program.sh $FILE $ASSIGN                # This partition is a test, just add as much arguments you need (Here there is no arguments)
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN  "225225"       # Um teste com 1 argumento que é "225225"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_program.sh $FILE $ASSIGN "8333325" "42"  # Um teste com 2 argumentos "8333325" e "42"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi 

# Aqui tem 3 testes, mas você pode adicionar quantos quiser.

touch .system/grading/passed;     # essa linha deve ficar no final do seu arquivo
```

E aqui está o segundo tester.sh *(FUNCTION EXERCICE)*:

 `👉 The only change is auto_correc_program who become auto_correc_main`

``` 
FILE='fprime.c'                                                  # Nome do exercicio
ASSIGN='fprime'                                                  # Nome da pasta

bash .system/auto_correc_main.sh 
$FILE $ASSIGN                # This partition is a test, just add as much arguments you need (In this example there is no arguments)
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_main.sh 
$FILE $ASSIGN  "225225"       # Um teste com 1 argumento que é "225225"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi

bash .system/auto_correc_main.sh 
$FILE $ASSIGN "8333325" "42"  # Um teste com 2 argumentos que são "8333325" e "42"
if [ -e .system/grading/traceback ];then
    mv .system/grading/traceback .
	exit 1
fi 

# Aqui tem 3 testes, mas você pode adicionar quantos quiser.

touch .system/grading/passed;     # Essa linha deve ficar no final do seu arquivo.
```

✅ Uma vez que você implementaru um novo exercicio, você pode testar usando o 42_EXAM (use o comando new_ex)

Once the exercise is perfectly added, you can ask for it to be added to the program on Github by making a 

pull request 😎
🔎 Esse video pode ajudar: [How to easily make a pull request](https://www.youtube.com/watch?v=rgbCcBNZcdQ)

Obrigado pela sua contribuição ❤️
