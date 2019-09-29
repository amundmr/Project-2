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

# 1. Abstract
First study a buckling beam problem  as a classical wave function problem in one dimension. Thereafter we extend the problem to quantum mechanics where electrons move in a three dimensional harmonic oscillator potential.  

<!-- TODO: Jacobi vs.  bisection -->

<!-- TODO: Importance of scaling equations? -->

# 2. Introduction
This project aims to look at different numerical methods for solving eigenvalue problems, which is relevant in a lot areas of physics. In this project we will also explore the eigenvalue solver's value specifically, with a quantum mechanics problem.
<!--TODO: Outline the problem briefly-->

We will solve the following equation:

$$-\frac{d^2u(\rho)}{d\rho^2}=\lambda u(\rho)$$ 

where $\rho$ and $\lambda$ are the scaled values from a given differential equation representing a physical system.
<!-- TODO: Jacobi's method -->

<!-- TODO: Scaling functions and quantum case -->

<!-- TODO: Bisection method -->



# 3. Theory and technicalities

# 3.1 The problem

In this project, we are considering two wave function problems in one dimension. Generally, the differential equation we are to solve can be written like this:

$$
  -\frac{d^2u(\rho)}{d\rho^2}=\lambda u(\rho).\ \ \ (1)
$$
<!-- TODO: Her må vi kanskje få fiksa ordentlig nummerering av likningene? Vet det fins en pandoc-plugin som gjør dette -->
This equation can be applied to both problems by making $\rho$ and $\lambda$ appropriate scaled values for the system in question. 

For the buckling beam, $u(x)$ is the displacement in the y-direction. With the length of the beam being $L$, we say that the scaled value $\rho=\frac{x}{L}$, where $x\in[0,L]$ is the distance along the beam. The variable $\rho$ is now defined in $[0,1]$ with boundary conditions for the scaled function $u(\rho)$, $u(0)=u(1)=0$ - nice and general.

<!-- TODO: Scaled values for quantum and buckling beam problem. -->

# 3.2 Orthogonal transformations

An orthogonal matrix $\mathbf{Q}$ has this property:

$$
  \mathbf{Q}^T\mathbf{Q}=\mathbb{I}\Rightarrow \mathbf{Q}^T=\mathbf{Q}^{-1}
$$

where $\mathbb{I}$ is the identity.

## 3.1 Jacobi's method

The Jacobi eigenvalue method is an iterative method for finding eigenvalues. It is based on the idea of doing a number of orthogonal basis transformations on the matrix in question, with the goal of diagonalizing it.

$$
  \mathbf{Q}_n^T\mathbf{Q}_{n-1}^T...\mathbf{Q}_1^T\mathbf{A}\mathbf{Q}_1...\mathbf{Q}_{n-1}\mathbf{Q}_n=\mathbf{D},
$$

where $\mathbf{A}$ is the starting matrix, $\mathbf{Q}_i$ are orthogonal matrices and $\mathbf{D}$ is diagonal, containing the eigenvalues.

---

We are solving the differential equation:

$$\\
\gamma d^2 \frac{u(x)}{dx^2} = -F u(x)
\\$$

where
- $u(x)$ is the vertical displacement in y -direction
- length of beam: L. $L \, \in \,  [0,L]$ where the force *F* is applied at (L, 0) in direction towards the origin.

$\gamma$, F and L are known variables.

Introduce dimensional variable in order to make our equation dimensionless(???????).

$$\rho = \frac{x}{L}$$

for $\rho \in [0,1]$

We can rewrite the equation as:

$$\\
\  \frac{d^2 u(\rho)}{d\rho^2} = \frac{-F L^2}{R} u(\rho) = -\lambda  u(\rho), \qquad \lambda = \frac{FL^2}{R}
\\$$

Our differential equation can now be discretised into an eingenvalue problem. Using the following expression for the second derivative (from Project 1) where stepsize = *h* defined from the max and min value of $\rho$, respectively $\rho_N$ and $\rho_0$.


$$\\
\  u'' = \frac{u(\rho + h) - 2 u(\rho) + u(\rho - h)}{h^2} - O(h^2),\qquad
h = \frac{\rho_N-\rho_0}{N}
\\$$

*N*: number of integration points.

Value of $\rho$ in point *i*:

$$\rho_i = \rho_0 + ih \qquad i = 1,2, \dots , N $$

Then our equation can be rewritten for the new $\rho_i$


$$\\
\   -\frac{u(\rho_i + h) - 2 u(\rho_i) + u(\rho_i - h)}{h^2}  = \lambda u(\rho_i)
\\$$

Compact:


$$\\
\ -  \frac{u_{i+1} - 2 u_i + u_{i-1}}{h^2}  = \lambda u_i
\\$$

Finally we can rewrite it as an eigenvalue problem

$$
\begin{equation}
\label{eq:1}
\tag{1}
\mathbf{Au = \lambda u},
\end{equation}
$$

where
$$\\
\mathbf A =\begin{bmatrix}
    d   &  a   &  0   &   0   &   \dots   &   0  &  0  \\
    a   &  d   &  a   &   0   &   \dots   &   0  &  0  \\
    0   &  a   &  d   &   a   &    0      &   \dots & 0 \\
    \dots & \dots & \dots & \dots & \dots & \dots & \dots\\
    0   &  \dots & \dots & \dots &    a   &     d & a   \\
    0   &  \dots & \dots & \dots &  \dots &     a & d   \\
\end{bmatrix}
\qquad \textrm{and} \qquad

\mathbf u =\begin{bmatrix}
    u_1 \\   u_2 \\ u_3 \\  \dots \\ u_{N-2} \\ u_{N-1}
\end{bmatrix}
\\$$

The endpoints, $u_0$ and $u_N$, are not included, and we will set $d = \frac{2}{h^2}$ and $a = -\frac{1}{h^2}$.

Now we can solve our equation numerically using Jacobi's method and compare with the analytical eingenvalues:

$$
\begin{equation}
\label{eq:2}
\tag{2}
\lambda_i = d + 2a \cos (\frac{j \pi}{N+1}) \qquad j = 1, 2, \dots, N.
\end{equation}
$$


<!-- Oppgave 2a) -->
In order to use Jacobi's method , we need to make sure that the unitary transformation preserves the orthogonality of the obtained eigenvectors.  So we assume that our basis of vectors $\mathbf v_i$

$$\\
\mathbf {v_i} =\begin{bmatrix}
    v_{i1} \\   \dots \\ \dots \\ v_{in} \\
\end{bmatrix}
\\$$

is orthogonal, meaning

$$\\
\mathbf{v}_j^T \mathbf v_i = \delta_{ij}.
\\$$

Our transformation reads as follow:

$$\\
\mathbf{w_i}=\mathbf{Uv_i}\\
\\$$

Multiplying the above equation from the left with
$$\\
\mathbf{w}_j^T=(\mathbf{U} \mathbf{v}_j)^T
\\$$
we get
$$\\
\mathbf{w}_j^T\mathbf{w_i}=(\mathbf{U} \mathbf{v}_j)^T \mathbf{Uv_i}\\
$$

$$\\
\mathbf{w}_j^T\mathbf{w_i}=\mathbf{v}_j^T\mathbf{U}^T \mathbf{Uv_i}\\
\\$$

Since $\mathbf{U^TU} = I$ (indentity matrix).

$$\\
\mathbf{w}_j^T\mathbf{w_i}  = \mathbf{v}_j^T\mathbf{v_i} = \delta_{ij}
\\$$

So orthogonality is preserved during the transformation.

<!-- Oppgave 2b) -->

In order to solve equation $\eqref{eq:1}$ we will implement Jacobi's rotation algorithm. But first we have to do the following:
- Diagolalize a matrix with a given size(NxN).
- Use armadillos functions for diagonalizing.
- Find analytical eigenvalues by $\eqref{eq:2}$ for comparison with the numerical ones.

In our Jacobi method we define the following:

$$\\
\tan\theta = t = s/c\\
s = \sin\theta\\
c = cos \theta \\
\cot 2\theta = \tau = \frac{a_{ll}-a_{kk}}{2a_{kl}}
\\$$

We define $\theta$ so all non diagnoal elements of the transformed matrix become non-zero.
Since

$$\cot2\theta = \frac{1}{2}(\cot\theta-\tan\theta)\\$$

We can rewrite as..
$$t^2 + 2\tau t - 1 = 0 , $$
giving
$$t = -\tau \pm \sqrt{1+\tau^2}.$$
Then
$$c = \frac{1}{\sqrt{1+t^2}} \quad \textrm{and} \quad s= tc$$



kilde til oppgave 2 a): http://www.math.harvard.edu/archive/21b_spring_08/handouts/orthomatrix.pdf
