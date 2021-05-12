#Cost = h * w + p0 * d0 + p1 * d1 + p2 * d2
#x <= h <= y; x0 <= p0 <= y0; x1 <= p1 <=y1; x2 <= p2 <= y2
from cvxopt import matrix, solvers
def findMinCost(w, d0, d1, d2, x, y, x0, y0, x1, y1, x2, y2):
  c = matrix([w, d0, d1, d2])
  #G = [-1 0 0 0 ; 1 0 0 0 ; 0 -1 0 0 ; 0 1 0 0 ; 0 0 -1 0 ; 0 0 1 0 ; 0 0 0 -1 ; 0 0 0 1 ]
  #h= [-x y -x0 y0 -x1 y1 -x2 y2 ]
  G = matrix([[-1., 1., 0., 0., 0., 0., 0., 0.], [0., 0. , -1., 1., 0., 0. ,0. , 0.], [0., 0. , 0, 0, -1., 1. ,0. , 0.], [0., 0. , 0, 0, 0., 0. ,-1. , 1.]])
  h = matrix([-x, y, -x0, y0, -x1, y1, -x2, y2])
  solvers.options['show_progress'] = False
  sol = solvers.lp(c, G, h)
  print(sol['x'])
  return sol['x']
#findMinCost(w=0., d0=0., d1=0., d2=1., x=1., y=1., x0=1., y0=1., x1=1., y1=1., x2=1., y2=1.)
  