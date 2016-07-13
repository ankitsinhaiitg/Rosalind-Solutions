def ReadDATA(inputfile): 

        # Reading from file.
        if inputfile[-4:] == '.txt':
                with open(inputfile) as f1:
                        return READ(f1)

def READ(f1):
        s1=[]
        for line in f1:

                if line[0] == '>':    #New DNA.
                        
                        try:
                                s1.append(dna)
                        except UnboundLocalError:
                                pass

                        dna = [line.lstrip('>').rstrip('\n'),'']

                else:
                        dna[1] += line.rstrip('\n')
        

        s1.append(dna)

        return s1


def mergemax(s):    #Merges overlaping sequences with maximum overlap.
	max_length = -1
	for prefix_index in xrange(len(s)):
		for suffix_index in [num for num in range(len(s)) if num != prefix_index]:
			prefix, suffix = s[prefix_index], s[suffix_index]
			i = 0
			while prefix[i:] != suffix[0:len(prefix[i:])]:
				i += 1
			if len(prefix) - i > max_length:
				max_length = len(prefix) - i
				max_indicies = [prefix_index, suffix_index]				
	return [s[j] for j in range(len(s)) if j not in max_indicies] + [s[max_indicies[0]] + s[max_indicies[1]][max_length:]]
def ShortestSuperstring(s):
	while len(s) > 1:
		s = mergemax(s)
	return s[0]
if __name__ == '__main__':
	s = [fasta[1] for fasta in ReadDATA('rosalind_long.txt')]
	superstring = ShortestSuperstring(s)	
	print superstring
	with open('results.txt', 'w') as result:
		result.write(superstring)

import os
os.system("pause")
