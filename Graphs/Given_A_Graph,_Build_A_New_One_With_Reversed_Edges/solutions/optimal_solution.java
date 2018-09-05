import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Solution {

    static class Node
    {
        Integer val;
        Vector<Node> neighbours = new Vector<Node>(0);
        Node(Integer _val)
        {
            val = _val;
            neighbours.clear();
        }
    };

	// ---- START ----

    /*
    In constraints we are given that each node contains distinct values, so we can keep track of 
    node address using that value. {value : node} 
    */
	static HashMap<Integer, Node> reversed_graph = new HashMap<Integer, Node>();

    static void dfs(Node node)
	{        
        // First create new node.
		reversed_graph.put(node.val, new Node(node.val));        
		int n = node.neighbours.size();
        // Visit all the neighbours.
		for (int i = 0; i < n; i++)
		{
            // If node is not visited then first visit it.
			if (reversed_graph.containsKey(node.neighbours.get(i).val) == false )
			{
				dfs(node.neighbours.get(i));
			}
            // Add the reverse edge. 
			reversed_graph.get(node.neighbours.get(i).val).neighbours.add(
                reversed_graph.get(node.val));
		}
	}

	static Node build_other_graph(Node node)
	{
        // Build the graph.
		dfs(node);
        // Return any node of the new graph. 
		return reversed_graph.get(1);
	}

	// ---- STOP ----

    static HashMap<Integer, Node> reversed = new HashMap<Integer, Node>();

    static void helper_dfs(Node reversed_node)
    {
        reversed.put(reversed_node.val, reversed_node);        
        int n = reversed_node.neighbours.size();
        for (int i = 0; i < n; i++)
        {
            if (reversed.containsKey(reversed_node.neighbours.get(i).val) == false)
            {
                helper_dfs(reversed_node.neighbours.get(i));
            }
        }
    }

    static HashMap<Integer, Node> helper_get_all_addresses_in_reversed_graph(Node reversed_node)
    {
        helper_dfs(reversed_node);
        return reversed;
    }

    static String helper(int graph_nodes, int[] graph_from, int[] graph_to) {
        int MAX_NODES = 315;
        
        HashMap<Integer, Node> original = new HashMap<Integer, Node>();
        for (int i = 1; i <= graph_nodes; i++)
        {
            original.put(i, new Node(i));
        }
        HashMap<Integer, Boolean> edges = new HashMap<Integer, Boolean>();
        int graph_edges = graph_from.length;
        for (int i = 0; i < graph_edges; i++)
        {
            original.get(graph_from[i]).neighbours.add(original.get(graph_to[i]));

            edges.put(MAX_NODES * (graph_from[i] - 1) + graph_to[i] - 1, true);
        }

        // Student will return only one node. Do a dfs and get all the nodes.
        HashMap<Integer, Node> reversed = helper_get_all_addresses_in_reversed_graph(build_other_graph(original.get(1)));

        if (reversed.size() != graph_nodes)
        {
            return "Wrong Answer!";
        }

        for (Integer val : reversed.keySet())
        {
            Node node = reversed.get(val);
            if (1 > val || val > graph_nodes)
            {
                return "Wrong Answer!";
            }
            // New graph should not contain node from original graph. 
            if (original.get(val) == reversed.get(val))
            {
                return "Wrong Answer!";
            }
            int n = node.neighbours.size();
            for (int i = 0; i < n; i++)
            {
                int _val = node.neighbours.get(i).val;
                int temp = MAX_NODES * (_val - 1) + val - 1;
                if (edges.containsKey(temp) == false)
                {
                    return "Wrong Answer!";
                }
                edges.remove(temp);
            }
        }
        // All the edges should be present in the new graph. 
        if (edges.size() > 0)
        {
            return "Wrong Answer!";
        }
        return "Correct Answer!";
    }

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String res;
        String[] graph_nodesm = in.nextLine().split(" ");
        int graph_nodes = Integer.parseInt(graph_nodesm[0]);
        int graph_edges = Integer.parseInt(graph_nodesm[1]);

        int[] graph_from = new int[graph_edges];
        int[] graph_to = new int[graph_edges];

        for (int graph_i = 0; graph_i < graph_edges; graph_i++) {
            String[] graph_fromv = in.nextLine().split(" ");
            graph_from[graph_i] = Integer.parseInt(graph_fromv[0]);
            graph_to[graph_i] = Integer.parseInt(graph_fromv[1]);
        }

        res = helper(graph_nodes, graph_from, graph_to);
        bw.write(res);
        bw.newLine();

        bw.close();
    }
}
