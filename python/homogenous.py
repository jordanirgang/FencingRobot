import sympy as sp

def Rot_x(angle):
    return sp.Matrix([[1,0,0,0],
                    [0,sp.cos(angle),-sp.sin(angle),0],
                    [0,sp.sin(angle),sp.cos(angle),0],
                    [0,0,0,1]])
def Rot_y(angle):
    return sp.Matrix([[sp.cos(angle),0,sp.sin(angle),0],
                    [0,1,0,0],
                    [-sp.sin(angle),0,sp.cos(angle),0],
                    [0,0,0,1]])
def Rot_z(angle):
    return sp.Matrix([[sp.cos(angle),-sp.sin(angle),0,0],
                    [sp.sin(angle),sp.cos(angle),0,0],
                    [0,0,1,0],
                    [0,0,0,1]])

def trans_x(l):
    return sp.Matrix([[1,0,0,l],
                    [0,1,0,0],
                    [0,0,1,0],
                    [0,0,0,1]])
def trans_y(l):
    return sp.Matrix([[1,0,0,0],
                    [0,1,0,l],
                    [0,0,1,0],
                    [0,0,0,1]])
def trans_z(l):
    return sp.Matrix([[1,0,0,0],
                    [0,1,0,0],
                    [0,0,1,l],
                    [0,0,0,1]])