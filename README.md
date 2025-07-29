# 📍 Cálculo de Rotas entre Cidades do Piauí

Este projeto simula a jornada de um viajante entre as cidades de **Corrente** e **Parnaíba**, no estado do **Piauí**, utilizando estruturas de **grafo direcionado** para representar as conexões rodoviárias entre as cidades. A partir disso, o algoritmo encontra **todos os caminhos possíveis**, o **menor caminho** e o **maior caminho**, com base na quantidade de cidades percorridas.

## 🎯 Objetivos

- Representar cidades como vértices de um grafo.
- Representar estradas como arestas direcionadas.
- Implementar um grafo inicialmente vazio.
- Adicionar conexões entre as cidades conforme o mapa fornecido.
- Percorrer todos os caminhos possíveis entre a cidade de origem (**Corrente**) e a de destino (**Parnaíba**).
- Identificar e exibir o caminho mais curto e o mais longo.
- Exibir o nome das cidades envolvidas em cada trajeto.

## 🧠 Algoritmos Utilizados

| Objetivo                | Algoritmo        | Justificativa |
|-------------------------|------------------|---------------|
| Todos os caminhos       | DFS (com pilha)  | Explora todas as possibilidades sem repetição |
| Caminho mais curto      | DFS + Comparação | Ideal seria BFS, mas é viável para grafos pequenos |
| Caminho mais longo      | DFS + Comparação | Aproveita a enumeração de caminhos da DFS |

> A estrutura `EstadoDFS` foi usada para armazenar o estado da busca com informações do caminho atual, profundidade e cidades visitadas.

## 🏙️ Cidades Representadas

| Índice | Cidade         |
|--------|----------------|
| 0      | Corrente       |
| 1      | Gilbués        |
| 2      | Bom Jesus      |
| 3      | Floriano       |
| 4      | Oeiras         |
| 5      | Teresina       |
| 6      | Campo Maior    |
| 7      | Piripiri       |
| 8      | Luís Correia   |
| 9      | Parnaíba       |

## 🛣️ Conexões (Estradas)

Conexões diretas entre as cidades:

```
Corrente → Gilbués → Bom Jesus → Floriano → Oeiras → Teresina
Teresina → Campo Maior → Piripiri → Luís Correia → Parnaíba
```

Rotas alternativas:

```
Teresina → Parnaíba
Bom Jesus → Teresina
```

## 🛠️ Tecnologias e Ferramentas

- Linguagem: **C**
- Estrutura de dados: **Lista de Adjacência**
- Algoritmos: **DFS**, estrutura de **pilha manual**
- Sistema: Compilável em Linux, Windows ou WSL com `gcc`

## ▶️ Como Executar

1. Compile o código:
   ```bash
   gcc -o rotas rotas.c
   ```

2. Execute o programa:
   ```bash
   ./rotas
   ```

3. Resultado esperado:
   - Lista de **todos os caminhos** possíveis de Corrente até Parnaíba.
   - Destaque para o **menor caminho** (menos cidades).
   - Destaque para o **maior caminho** (mais cidades).

## 📋 Saída Esperada (Exemplo)

```
Todos os caminhos de Corrente até Parnaíba:

Caminho 1 (10 cidades): Corrente -> Gilbués -> Bom Jesus -> Floriano -> Oeiras -> Teresina -> Campo Maior -> Piripiri -> Luís Correia -> Parnaíba
Caminho 2 (7 cidades): Corrente -> Gilbués -> Bom Jesus -> Teresina -> Campo Maior -> Piripiri -> Luís Correia -> Parnaíba
Caminho 3 (6 cidades): Corrente -> Gilbués -> Bom Jesus -> Teresina -> Parnaíba

Menor caminho (6 cidades): Corrente -> Gilbués -> Bom Jesus -> Teresina -> Parnaíba
Maior caminho (10 cidades): Corrente -> Gilbués -> Bom Jesus -> Floriano -> Oeiras -> Teresina -> Campo Maior -> Piripiri -> Luís Correia -> Parnaíba
```

## 📘 Créditos e Autoria

Este código foi desenvolvido para fins educacionais, com foco no entendimento de grafos, listas de adjacência e algoritmos de busca em profundidade (DFS). 

---
