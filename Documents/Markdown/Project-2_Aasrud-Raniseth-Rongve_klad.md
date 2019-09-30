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
An eigenvalue solver is extremely important in many different types of calculations and is thus of interest for many scientists. We will demonstrate this by calculating the eigenvalues for both a buckling beam problem and an quantum mechanical problem. The eigenvalue algorithm mainly explored in this paper is the Jacobi eigenvalue algorithm first proposed by Carl Gustav Jacob Jacobi. He proposed this algorithm already in 1846 [@Jacobi1846], but it only became widely used with the rise of the computer in the 1950s.

We will also compare this to another method called the bisection method.






# 3. Theory and technicalities

# 3.1 The problem

In this project, we are considering two wave function problems in one dimension. Generally, the differential equation we are to solve can be written like this:

$$
  -\frac{d^2u(\rho)}{d\rho^2}=\lambda u(\rho).\ \ \ (1)
$$
<!-- TODO: Her må vi kanskje få fiksa ordentlig nummerering av likningene? Vet det fins en pandoc-plugin som gjør dette -->
This equation can be applied to both the buckling beam and the quantum mechanical problem by making $\rho$ and $\lambda$ appropriate scaled values for the system in question.

For the buckling beam, $u(x)$ is the displacement in the y-direction. With the length of the beam being $L$, we say that the scaled value $\rho=\frac{x}{L}$, where $x\in[0,L]$ is the distance along the beam. The variable $\rho$ is now defined in $[0,1]$ with boundary conditions for the scaled function $u(\rho)$, $u(0)=u(1)=0$ - nice and general.

For the quantum mechanical problem, $u(\rho)$ is the root of the probability density for an electron to be positioned at a distance $r$ from the origin. The variable $\rho$ is defined as $\frac{1}{\alpha}r$ where $\alpha$ is a scaling factor. How this scaling factor is found, you can see below in section \ref(sec:QM-theory).

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

$$\\
\begin{equation}
\label{eq:1}
\tag{1}
\mathbf{Au = \lambda u},
\end{equation}
\\$$

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
- Diagonalize a matrix with a given size($N \times N$).
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

<!-- Oppgave 2d) -->
### Applying these methods to quantum calculations \label(sec:QM_theory)
To demonstrate that our eigenvalue solver is capable we will apply it on a quantum mechanical problem with one electron as a quantum dot in 3-dimensional space stuck in an harmonic oscillator potential. What we do is to make the Schroedinger equation with spherical coordinates work with our solver. That means that we eliminate the constants by introducing a variable and then discretizing the differential equation so we can make a tridiagonal matrix which will be the input to our eigenvalue solver.

With these eigenvalues it is possible to calculate the energy and position of the electron, but we will not demonstrate that here. We will in stead investigate what number of integration points, $N$, and what approximation of infinity we can use to get sufficiently correct eigenvalues.

The following assumptions are made:
- Electrons move in a three-dimensional harmonic oscillator potential.
- They repel each other via the static Coulomb interaction.
- There is spherical symmetry.
- The radial position $u(r)$ has boundary conditions $u(0) = 0$ and $u(\infty) = 0$.

The spherical part of Schroedinger's equation reads as follows:

\[-\frac{\hbar^2}{2m}\left(\frac{1}{r^2}\frac{d}{dr}r^2\frac{d}{dr} - \frac{l(l+1)}{r^2}\right) R(r) + V(r)R(r) = ER(r)\]

Where $V(r)$ is the harmonic oscillator potential $\frac{1}{2}kr^2$ with $k=m \omega^2$ and E is the energy of the harmonic oscillator. The quantum number $l$ is the orbital momentum of the electron and the oscillator frequency is $\omega$ and its energies are

\[E_{nl} = \hbar \omega \left(2n + l + \frac{3}{2} \right)\]

Where \
$n = 0,1,2,..$ and $l = 0, 1, 2, ...$

Since this is already transformed to spherical coordinates, we have $r \in [0, \infty)$

If we substitute $R(r) = \frac{1}{r}u(r)$ we get

\[-\frac{\hbar}{2m}\frac{d^2}{dr^2}u(r) + \left( V(r) + \frac{l(l+1)}{r^2}\frac{\hbar^2}{2m}\right)u(r) = Eu(r)\]

The next thing to do is to introduce a dimensionless variable $\rho$ which contains a variable $\alpha$ which we can later define so that we can transform our spherical Schroedinger's equation to an eigenvalue problem which we can solve using our Jacobi's method eigenvalue solver described above. \ref(sec:Jacobi)

If $\rho = \frac{1}{\alpha} r$ the equation reads:

\[-\frac{\hbar^2}{2m\alpha^2}\frac{d^2}{d\rho^2}u(\rho) +  \left( V(\rho) + \frac{l(l+1)}{\rho^2}\frac{\hbar^2}{2m\alpha^2}\right)u(\rho) = Eu(\rho)\]
Multiplying both sides by $2m\alpha^2/\hbar^2$ we get
\[-\frac{d^2}{d\rho^2}u(\rho) + \frac{mk}{\hbar}\alpha^4\rho^2u(\rho) = \frac{2m\alpha^2}{\hbar^2}Eu(\rho)\]
We can now fix the constant $\alpha$ to eliminate all the constants.
\[\frac{mk}{\hbar^2}\alpha^2 = 1 \hspace{1cm} \rightarrow \hspace{1cm} \alpha = \left(\frac{\hbar^2}{mk}\right)^{1/4}\]

If we now define
\[\lambda = \frac{2m\alpha^2}{\hbar^2}E\]
The Schroedinger's equation can be rewritten as
\[-\frac{d^2}{d\rho^2}u(\rho) + \rho^2u(\rho) = \lambda u(\rho)\]
This is a similar problem to the buckling beam we described above. So summarize, the compact discretized Schroedinger equation will be
\[-\frac{u_{i+1} - 2u_i + u_{i-1}}{h^2} + V_i u_i = \lambda u_i\]
Where $V_i = \rho_i^2$ and $h$ is the steplength.
From this it is clear that on tridiagonal matrix form it is written
$$\\
\begin{bmatrix}
    d_i   &  e_i   &  0   &  \dots    &   \dots   &   \dots  &  0  \\
    e_i   &  d_i   &  e_i   &   0   &   \dots   &  \dots   &  0  \\
    0   &  e_i   &  d_i   &   e_i   &    0      &   \dots & 0 \\
    \vdots & 0 & \ddots & \ddots & \ddots &  & \vdots\\
    \vdots   &  \vdots &  & 0 &    e_i   &     d_i & e_i   \\
    0   &  \dots & \dots & \dots &  0 &     e_i & d_i   \\
\end{bmatrix}

\begin{bmatrix}
    u_1 \\   u_2 \\ u_3 \\  \vdots \\ u_{N-2} \\ u_{N-1}
\end{bmatrix}

= \lambda \begin{bmatrix}
    u_1 \\   u_2 \\ u_3 \\  \vdots \\ u_{N-2} \\ u_{N-1}
\end{bmatrix}
\\$$
Where the diagonal elements are
\[d_i = \frac{2}{h^2} + V_i\]
and the non-diagonal elements is a constant given by
\[e_i = -\frac{1}{h^2}\]

It is now clear that the eigenvalue solver we made will be able to find these eigenvalues. However it will have to be tweaked by finding a sufficient number of integration points, $N$ and an approximation of $\rho_{max}$ to infinity that yields eigenvalues close enough to the analytical ones of which the first four is $\lambda = 3,7,11,15$.

To do this we fix $\rho_{max} = 10$ and find the average deviation of our calculated ones from the analytical ones for $N = {100, 200, 300, 400}$ and plot the error and time versus the number of integration points. This can be found in the d branch in [_/Code/Quantum-case/main.cpp_](https://github.com/amundmr/Project-2/blob/master/Code/Quantum-case/main.cpp)

Then we fix the number of integration points to $N = 200$ and calculate the average error for the approximations $\rho_{max} = {4, 5, 6, 7, 8, 9, 10, 11}$ and plot the error and time versus the approximation of $\rho_{max}$. This can be found in the d branch in [_/Code/Quantum-case/main_rho.cpp_](https://github.com/amundmr/Project-2/blob/master/Code/Quantum-case/main_rho.cpp)


# Results


### Quantum mechanics eigenvalue calculations
The investigation of a sufficient amount of integration points, $N$ gave us the plot shown in figure \ref(fig:int-points).

![Shows time spent and average error vs number of integration points, $N$](../Images/int-points-plot.png)

The investigation of the best approximation to infinity gave us the plot shown in figure \ref(fig:rho-approx).

![Shows time spent and average error vs approximation of infinity](../Images/rho_approx_plot.png)
It is also worth noting that all these graphs are reproducible, except the time graph of the approximation of $\rho_{max}$ which were very different every time.


# Discussion

### Quantum mechanics eigenvalue calculations
From the figures presented in the results we see that while a higher number of integration points yields better results, a big downside is that the time spent also increases.

With the changing of $\rho_{max}$ we see that first the error decreases, but after $\rho_{max} = 5$ we actually start to see an increase in error again. This might be because a higher $\rho_{max}$ gives a bigger step-size which again gives lower numbers on the off-diagonal elements, which in turn yields a lower amount of Jacobi rotations before the off-diagonal elements are below the tolerance for being called zero.

The time spent on the calculations seem pretty random and that is probably because the changing of $\rho_{max}$ doesn't make the computer do any more or less work, it simply changes the numbers. The fluctuations might therefore just be that the computer has different background tasks running at different times.
