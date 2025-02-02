# Projeto: Tarefa de Interrupção na BitDogLab

Bem-vindo ao meu repositório sobre a tarefa de interrupção na placa de desenvolvimento educacional BitDogLab. Este projeto faz parte da unidade de microcontroladores do programa de capacitação profissional técnica EmbarcaTech e tem como principal objetivo o aprendizado sobre o uso de interrupções.

## Funcionalidades
- **Matriz de LEDs:** Exibe números de 0 a 9, com os números podendo ser incrementados ou decrementados pelos usuários por meio de botões.
- **LED Central:** Pisca cinco vezes por segundo, demonstrando o uso de timers e controle de LED.

Explore o repositório para ver o código, entender o funcionamento e aprender como as interrupções são aplicadas neste projeto.


## Componentes Utilizados

### Hardware
- **Microcontrolador RP 2040**
- **Raspberry Pi Pico W**
- **LED RGB**
- **Matriz de LED RGB**
- **Push Buttons**

### Software
- **Linguagem C**
- **IDE Visual Studio Code**
- **Extensões do Visual Studio Code**:
  - Raspberry Pi Pico
  - CMake Tools
  - Wokwi
  - C/C++

 ### **Pré-requisitos para utilização**
Certifique-se de que os seguintes itens estão instalados:

1. **Visual Studio Code**  
   - Ambiente de desenvolvimento integrado (IDE) para edição, compilação e depuração do código.

2. **Git**  
   - Ferramenta para versionamento de código e controle de repositórios.  

3. **Extensões do Visual Studio Code**  
   - **C/C++**: Suporte à linguagem C/C++ para análise de código, depuração e IntelliSense.  
   - **CMake Tools**: Para gerenciar e configurar projetos que utilizam o CMake.  
   - **Raspberry Pi Pico**: Extensão para facilitar o desenvolvimento e a comunicação com a placa Raspberry Pi Pico.  

4. **Zadig**  
   - Software necessário para instalar drivers USB.  
   - Permite a conexão via USB da placa Raspberry Pi Pico com o desktop ou notebook.  

5. **Versão 2.0.0+ do Raspberry Pi Pico SDK**  
   - Certifique-se de que a versão 2.0.0 ou superior do SDK para Raspberry Pi Pico está instalada.  
---

## **Como executar o Projeto**

### **1. Configuração Inicial**
1. Certifique-se de que todas as dependências acima estão instaladas no seu computador.
2. Clone o repositório do projeto usando os comandos abaixo no terminal:  
   ```bash
   git init
   git clone [link do repositório]
3. Abra o projeto clonado no VS Code

### **2. Compilação e Carregamento na Placa**
1. Compile o projeto clicando na opção "**Compile Project**" da extensão Raspberry Pi Pico no **Visual Studio Code**.
2. Após a compilação bem-sucedida, conecte a Raspberry Pi Pico W ao computador utilizando um cabo USB.
3. Coloque a placa em modo **BootSel**:
   - Pressione e segure o botão **BOOTSEL** enquanto conecta a placa pelo cabo USB.
   - Caso esteja utilizando a BitDogLab, aperte o botão **RESET** enquanto pressiona e segura o botão **BOOTSEL** (este método não exige a reconexão do cabo USB) 
4. Localize o arquivo gerado com extensão .uf2 (como **tarefa_interrupcao.uf2**) e arraste-o para o dispositivo que aparecerá no computador.

### 3. Operação na Prática

1. Inicie a placa.
2. Use os botões para interagir com a matriz de leds:
   - Pressione o botão A para incrementar o número exibido na matriz.
   - Pressione o botão B para decrementar o número exibido na matriz.

  ## **Vídeo de Apresentação do Projeto**
Confira a playlist com vídeos de apresentação do projeto clicando no ícone abaixo:

<a href="https://youtube.com/shorts/LU2o8_zva78">
  <img src="https://img.icons8.com/color/48/000000/youtube-play.png" alt="YouTube" />
</a>
