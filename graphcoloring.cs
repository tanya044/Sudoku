int colorNumber = 1; //number of used colors
int numberOfColoredNodes = 0;

while (numberOfColoredNodes < graph.Count)
{
 var max = -1;
 var index = -1;

 for (int i = 0; i < graph.Count; i++)
 {
  if (!Colored(graph.Nodes[i], nodeSet))
  {
   var d = SaturatedDegree(graph.Nodes[i], nodeSet);
   if (d > max)
   {
    max = d;
    index = i;
   }
   else if (d == max)
   {
    if (Degree(graph.Nodes[i]) > Degree(graph.Nodes[index]))
    {
     index = i;
    }
   }
  }
 }
 AssignColor(graph.Nodes[index], nodeSet,ref colorNumber);
 numberOfColoredNodes++;
}
