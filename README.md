# N-Body-Using-MPI
N-Body Simulation using MPI for message passing and OpenGL for visualization

N-body simulation is a simplified graphical simulation of bodies moving through space following Newtonian mechanics. You can find out more about n-body simulations on Wikipedia: https://en.wikipedia.org/wiki/N-body_simulation

For this exercise, we have 1000 bodies with their initial x and y position and their mass given in input.txt


## Understanding Newtonian Movements

Our simulation follows rather simple formulas for two-dimensional space. We start with the basics:

(I) 2D-Motion: The velocity vector will have an x and y direction; by the Pythagorean theorem: v = sqrt(v_x^2 + v_y^2)

(II) Change of Position: With s the change in position and u the initial velocity, we can compute any positional change by s_x = u_x + (1/2)a_x * t^2  [analogous for y]

(III) Newton's famous Second Law: F = ma

Then, we finally arrive at a formula that takes into account all the forces acting between all of the n bodies:

(IV) F = sum[i to N excl n]{ (G * m_n * m_i)/(r_ni^2) * r'_ni } with G the gravitational constant, m_n the mass of the particle currently observed, m_i the mass of the other particle acting on n, r_ni the magnitude of the vector in terms of its components and r'_ni the vector as a distance between n and i 

r'_ni will then be separately analyzed for x and y axes respectively.


## Message Passing Interface

The most important aspect of any n-body simulation is to reduce the amount of unnecessary computations -- if x has been given the distance to y, y has no to calculate the distance to x again. Using MPI AllGather makes use of the Hypercube model and works effectively. 
