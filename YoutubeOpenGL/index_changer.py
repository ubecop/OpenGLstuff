def triangle_indices(input_file, output_file):
    with open(input_file, 'r') as infile:
        lines = infile.readlines()

    with open(output_file, 'w') as outfile:
        for line in lines :
            indices = line.split()
            if len(indices) == 4:
                i0, i1, i2, i3 = indices
                # First triangle
                outfile.write(f"{i0} {i1} {i2}\n")
                # Second triangle
                outfile.write(f"{i0} {i2} {i3}\n")
            else:
                # if the line doesn't have 4 indices, copy it as it is
                outfile.write(line)

input_file = 'C:/Users/matts/Documents/Satellite_stuff/indices.txt'
output_file = 'C:/Users/matts/Documents/Satellite_stuff/triangle_indices.txt'

triangle_indices(input_file, output_file)