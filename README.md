# MAC0214
## Proposta
Para as apresentações de taiko, muitas vezes fazemos mapas do palco utilizando
a ferramenta de formas do Excel ou desenhando no papel mesmo. Conversando
com pessoas da comunidade do taiko, a qual faço parte, dei a ideia de ter um
programa que seja especializado nisso.

O software possibilitará ao usuário que ele coloque as dimensões do palco
para criar uma grade quadriculada que representa o palco com marcações demetro em 1 metro e que sejam adicionados instrumentos no palco com o mouse, bastando clicar em uma lista de instrumentos e arrastar.

O usuário também poderá adicionar instrumentos novos, salvar e carregar
mapas.

Esses são os usos mais comuns do projeto, os quais eu pretendo implementar
esse semestre.

### Supervisor
Entrei em contato com o Daniel Picanço da ABT (Associação Brasileira de
Taiko) e ele estará supervisionando o trabalho. O contato da ABT pode ser
encontrado na página do facebook https://www.facebook.com/taikobrasil/

### Objetivos
O objetivo do trabalho é contribuir para a comunidade de taiko do Brasil (e possivelmente do mundo), além de aprender a lidar com ferramentas de interface gráfica como o Qt e me habituar ao desenvolvimento de software em geral.

### Etapas
Primeiramente eu tenho que aprender a usar o Qt. Após saber usar o básico da ferramenta, vou desenvolver uma versão primitiva do projeto com as funcionalidades básicas. Após isso, vou evoluindo o design e as funcionalidades dosoftware conforme a necessidade e conforme o que eu julgar mais importante a ser feito no momento.

### Cronograma
Vou tentar trabalhar cerca de 6 horas semanais a partir da semana do dia 20
de agosto. Até lá vou estudando as ferramentas necessárias.

### Acompanhamento
Toda semana vou tentar adicionar um capı́tulo neste documento com um pequeno relatório do trabalho desenvolvido na semana.
Este documento estará disponı́vel, junto com o trabalho, no repositório
https://github.com/GabrielLasso/MAC0214.git


## Semana 12/08
Nessa primeira semana eu aprendi o básico de Qt e implementei uma versão básica do aplicativo que cria mapas e carrega mapas salvos.

Os mapas consistem de uma grade quadriculada e um quadrado representando cada instrumento.

O arquivo se mapa carregado é um arquivo
```
altura,largura
x1,y1
x2,y2
...
```
como o arquivo mapa_exemplo no commit https://github.com/GabrielLasso/MAC0214/tree/09432ae637ffa739ac54aa8b5cfe9bb63a348ab0.
