---
title: Project 2
author:
  - Knut Magnus Aasrud
  - Anna Stray Rongve
  - Amund Midtgard Raniseth
date: 30 September 2019
header-includes: |
  \usepackage{fancyhdr}
  \pagestyle{fancy}
  \fancyhf{}
  \rhead{Project 2}
  \lhead{\leftmark}
  \rfoot{\thepage}
---

# Project 1 a)
$$\\
\mathbf{U}^T\cdot|\,\mathbf{Uv_j}\cdot \mathbf{Uv_i} =
\mathbf{I_n} \mathbf{v_j U v_i} \\
\\$$

which you can write as the matrix product

$$\\
\mathbf{v_j^TUv_i} = (\mathbf{U^Tv_j})^T \mathbf{v_i} = \mathbf{U}^T \mathbf{v_jv_i}\\
\\
\\$$

multiply by $\mathbf{U}$ from the left and get
$$\\
\mathbf{UU}^T \mathbf{v_jv_i} = \mathbf{v_jv_i}
\\$$
---
$$(\mathbf{Uv}_j)^T\mathbf{Uv}_i=\mathbf{v}_j^T\mathbf{U}^T\mathbf{Uv}_i=\mathbf{v}_j^T\mathbb{I}\mathbf{v}_i=\mathbf{v}_j\mathbf{v}_i
\\$$
--



kilde til oppgave 2 a): http://www.math.harvard.edu/archive/21b_spring_08/handouts/orthomatrix.pdf
