using System;
using System.Collections.Generic;

namespace _03_Graphs
{
    public class Program
    {
        private static int verticesCount;
        private static bool[,] graph;
        private static HashSet<string> uniqueCycles;

        public static void Main()
        {
            verticesCount = int.Parse(Console.ReadLine());
            graph = new bool[verticesCount, verticesCount];

            for (var i = 0; i < verticesCount; i++)
            {
                int vertex;
                int[] vertexDestinations;
                ReadLineVertex(out vertex, out vertexDestinations);
                for (var ii = 0; ii < vertexDestinations.Length; ii++)
                {
                    graph[vertex, vertexDestinations[ii]] = true;
                }
            }

            uniqueCycles = new HashSet<string>();

            List<int> list = new List<int>();
            bool[] visited = new bool[verticesCount];

            for (var i = 0; i < verticesCount; i++)
            {
                if (!visited[i])
                {
                    list.Clear();
                    list.Add(i);
                    visited[i] = true;
                    TraversePath(i, list);
                }
            }

            if (uniqueCycles.Count == 0)
            {
                Console.WriteLine("No cycles found");
            }
        }

        private static void TraversePath(int vertex, List<int> list)
        {
            if (list.Count == 3)
            {
                int firstVertex = list[list.Count - 3];
                int lastVertex = list[list.Count - 1];
                if (graph[lastVertex, firstVertex])
                {
                    AddTriVertexCycle(list);
                    return;
                }
            }
            else
            {
                for (var i = 0; i < verticesCount; i++)
                {
                    if (graph[vertex, i])
                    {
                        if (!list.Contains(i))
                        {
                            list.Add(i);
                            TraversePath(i, list);
                            list.RemoveAt(list.Count - 1);
                        }
                    }
                }
            }
        }

        private static void AddTriVertexCycle(List<int> list)
        {
            Queue<int> queue = new Queue<int>();
            int minVertex = Int32.MaxValue;

            for (var i = 0; i < 3; i++)
            {
                int vertex = list[list.Count - 3 + i];
                if (vertex < minVertex)
                {
                    minVertex = vertex;
                }
                queue.Enqueue(vertex);
            }

            while (minVertex != queue.Peek())
            {
                queue.Enqueue(queue.Dequeue());
            }

            string str = "{" + string.Join(" -> ", queue) + "}";
            if (!uniqueCycles.Contains(str))
            {
                uniqueCycles.Add(str);
                Console.WriteLine(str);
            }
        }

        private static void ReadLineVertex(out int vertex, out int[] vertexDestinations)
        {
            string input = Console.ReadLine();
            string[] inputs = input.Split(' ');
            vertex = int.Parse(inputs[0]);
            List<int> destinations = new List<int>(inputs.Length - 2);

            for (var i = 2; i < inputs.Length; i++)
            {
                destinations.Add(int.Parse(inputs[i]));
            }

            vertexDestinations = destinations.ToArray();
        }
    }
}
