# Python script to generate random graphs for testing minimum spanning tree algorithms.
# Credits given to Dr. Tillquist.

import numpy as np
import networkx as nx

if __name__=='__main__':
    n = 100
    for i in range(5): #Erdos-Renyi random graphs
        G = nx.erdos_renyi_graph(n, 0.1)
        nx.set_edge_attributes(G, {e:{'weight': np.random.randint(1, 10)} for e in G.edges()})
        nx.write_weighted_edgelist(G, 'er_'+str(i)+'.edgelist')

    for i in range(5): #Barabasi-Albert random graphs
        G = nx.barabasi_albert_graph(n, 3)
        nx.set_edge_attributes(G, {e:{'weight': np.random.randint(1, 10)} for e in G.edges()})
        nx.write_weighted_edgelist(G, 'ba_'+str(i)+'.edgelist')

    for i in range(5): #random tree
        G = nx.random_tree(n)
        nx.set_edge_attributes(G, {e:{'weight': np.random.randint(1, 10)} for e in G.edges()})
        nx.write_weighted_edgelist(G, 'tree_'+str(i)+'.edgelist')
