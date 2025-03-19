##Cpp Unit

O CPPUnit é um framework de testes unitários para C++ baseado no Junit. 



##Intalação e pré Requisitos

Para instalar o CPP Unit no Linux - Ubuntu utilizar o comando abaixo dentro do seu repositório.

        sudo apt update
        sudo apt install libcppunit-dev

##Tutorial

Para demonstrar a ferramenta foi criado um exemplo básico de um conjunto de 3 funções: Máximo, ParImpar e fatorial.

Para criar uma suíte de testes utilizando o CppUnit, deve-se inicialmente definir uma classe de teste que herda de TestFixture e a definição de testes individuais usando o macro CPPUNIT_TEST.

                class test_maximo : public TestFixture {



##Aspectos Positivos da Ferramenta

        - Relativamente fácil de implementar os testes;



##Aspectos Negativos da Ferramenta

        - Ela não mostra cobertura de código (para fazer isso é necessário integrar por exemplo o lcov)
        