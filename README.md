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

## Semana 19/08
Agora o aplicativo suporta vários mapas carregados ao mesmo tempo, ficando separados em abas, e cada um fica em uma área delimitada, o que deixa mais organizado.

Além disso, agora se poe adicionar instrumentos novos clicando em um botão, pode-se dar zoom no mapa e dá pra salvar e carregar os mapas salvos.

O arquivo que o mapa é salvo agora tem a seguinte forma:
```
altura,largura
x1,y1,instrumento1
x2,y2,instrumento2
...
```

## Semana 26/08
Foram adicionadas as seguintes ferramentas:
- Uma lista de instrumentos que busca todas as imagens na pasta Images/
- Seleção de instrumentos. Vários instrumentos selecionados se movem juntos.
- Apertar delete apaga os instrumentos selecionados
- O zoom pode ser dado com a roda do mouse
- É possível mover instrumentos selecionados com as setas

## Semana 02/09
Criei um header no mapa contendo noe da música, nome da equipe e cidade da equipe.

Além disso, importei algumas imagens de instrumentos usadas nos mapas do CFWU2018 para ver como ficam os mapas.

## Semana 09/09
Eu possibilitei girar os instrumentos de 15 em 15 graus e modifiquei o arquivo de save para que essa informação fique guradada.

Agora o arquivo de save é assim:
```
Nome da música
Equipe
Cidade
altura,largura
x1,y1,alpha1,instrumento1
x2,y2,alpha2,instrumento2
...
```

Também mudei um pouco o design da edição do header e possibilitei editar o tamanho do mapa.

## Semana 16/09
Essa semana eu no consegui trabalhar as 6 horas previstas  no projeto, só trabalhei cerca de 3 horas. Vou tentar compensar isso nas outras semanas.

Adicionei a opção de exportar para PNG e criei uma lista de instrumentos usados ao lado do mapa

## Semana 23/09
- Adicionei shortcuts para novo mapa, carregar mapa e salvar mapa
- Arrumei o tamanho da imagem exportada
- Tirei os botões de editar propriedades e de exportar imagem e coloquei opções no menu
- Melhorei as configurações do FileDialog
- Mudei o input para rotacionar os intrumentos
- Importei mais imagens
- Ordenei a lista de instrumentos alfabeticamente
- Arrumei o posicionamento dos textos
- Arrumei um bug que quando deletava um instrumento não atualizava a lista de instrumentos usados

## Semana 30/09
Essa semana eu quis adicionar ferramentas de copiar/colar e de desfazer/refazer.

A de copiar e colar eu consegui fazer sem dificuldades.

A de desfazer e refazer foi mais complicada. Eu pesquisei como funcionam as classes QUndoCommand e QUndoStack e vi que precisaria descobrir de alguma forma quando um instrumento é movido. Para isso tive que mudar algumas fuções insternas da classe QGraphicsItem, e isso levou mais tempo do que eu imaginei. Agora que o sinal está pronto será fácil fazer os comandos de desfazer e refazer.

Também vi que o software não roda em computadores que não tenham o Qt instalado, aí pesquisei o que fazer e existe uma ferramenta que cria instalador que já arruma as dependências. Estou aprendendo a usar isso.

## Semana 07/10
Essa semana eu aprendi como dar deploy e criar um installer e consegui criar o comando de desfazer-refazer para quase tudo. Só falta redo() para mover e rotacionar que, por algum motivo, está dando segfault.

## Semana 14/10
Arrumei o undo e redo para mover e rotacionar. Para isso tive que mudar quando os sinais são enviados

## Semana 21/10
Vários bugs relacionados a undo/redo corrigidos.

- Mover itens rotacionados não funcionava corretamente
- Mover vários itens de uma vez exigia vários redos para uma só ação
- Rotacionar vários itens de uma vez exigia vários redos para uma so ação
- Clicar em um ítem criava um redo vazio

## Semana 28/10
Estou deixando os instrumentos de tamanhos mais realistas. O software já está num nível bom de usabilidade e só faltam esses detalhes mesmo

## Mês de novembro
No mês de novembro, não mantive o padrão de 6 horas por semana por conta do TCC.

No entanto, realizei várias coisas:
- Criei o pôster da diciplina, disponível em https://pt.overleaf.com/read/gbtvwffwwysr
- Foi identificado um problema no deploy pra windows, instalei windows em um computador meu para testar isso
- Apareceram pessoas das comunidades de taiko da Bahia e do Paraná interessadas no projeto
- O projeto foi apresentado em uma reunião da Associação Brasileira de Taiko
- Escrevi o relatório final da disciplina
