import re


def takeNumFaces(filepath):
    with open(filepath, 'r') as file:
        lines = file.readlines()
        second_line = lines[1].strip()
        numbers = second_line.split()
        faces = int(numbers[1])
    return(faces)

def takeNumPoints(filepath):
    with open(filepath, 'r') as file:
        lines = file.readlines()
        second_line = lines[1].strip()
        numbers = second_line.split()
        points = int(numbers[2])
    return(points)

geofile = "C:/Users/matts/Documents/Satellite_stuff/SES25.geo"

geofaces = takeNumFaces(geofile)
facepoints = takeNumPoints(geofile)
#print(geofaces, facepoints)

def gatherVertices(filepath):
    vertices = []
    unique_vert = []
    index = 0
    with open(filepath, 'r') as file:
        lines = file.readlines()
        for line in lines[2 : 2*geofaces + 2]:
            parts = re.findall(r'[-0]\.\d+E[+-]\d{2}', line)
            # print(parts)
            for i in range(0, len(parts), 3):
                vertex = [parts[i], parts[i+1], parts[i+2]]
                #print(vertex)
                vertices.append(vertex)
        
    return vertices
                
vertices = gatherVertices(geofile)


def createUniqueVerticesDict(vertexlist):
    unique_vertices = {}
    for index, vertex in enumerate(vertexlist):
        if vertex not in unique_vertices.values():
            unique_vertices[index] = vertex
        #print(vertex)
    return unique_vertices

unique_vert = createUniqueVerticesDict(vertices)
#print(len(unique_vert))
print(unique_vert.items())

index_list = []

for vertex in vertices:
    for key, value in unique_vert.items():
        if vertex == value:
            index_list.append(key)
            break

#print(index_list)
#print(len(index_list))

def groupFaces(indices):
    faces = [indices[i:i+4] for i in range(0, len(indices), 4)]
    return faces

face_list = groupFaces(index_list)
# for face in face_list:
#     print(face)
print(len(face_list))

object_dimension = 3

groupsize = facepoints // object_dimension 

def write_off(offpath):
    with open(offpath, 'w') as file:
        file.write("OFF\n")
        file.write(f"{len(vertices)} {geofaces} 0\n")

        for vertex in vertices:
            file.write(" ".join(vertex) + "\n")

        for face in face_list:
            line = f"{groupsize} " + " ".join(map(str, face)) + "\n"
            file.write(line)


off_file = "C:/Users/matts/Documents/Satellite_stuff/SES25.off"

write_off(off_file)

