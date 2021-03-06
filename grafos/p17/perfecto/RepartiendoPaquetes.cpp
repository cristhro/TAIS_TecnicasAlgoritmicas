#include "RepartiendoPaquetes.h"
#include <limits>

RepartiendoPaquetes::RepartiendoPaquetes(const GrafoDirigidoValorado<double>  &G, int s )
	:	
		distTo(G.V(),    std::numeric_limits<double>::infinity()),
		edgeTo(G.V(), AristaDirigida<double>(0, 0, 0)),
		pq(G.V())
{

	distTo[s] = 0.0;
	pq.push(1, 0);
	//O((v * log v ) + (e * log v)  )   = O(e*log v)
	while (!pq.empty()  ) {  
		
		// O(v log v)
		int v; v = pq.top().elem; pq.pop();

		// O( e log v)
		for (AristaDirigida<double> e : G.adj(v))
		{
			relax(e);
		}
		
	}
}


bool RepartiendoPaquetes::imposible() {
	return false;

}

// O( log v)
void RepartiendoPaquetes:: relax(const AristaDirigida<double> &e)
{
	int v = e.from(), w = e.to();

	if (distTo[w] > distTo[v] + e.valor()) 
	{
		distTo[w] = distTo[v] + e.valor();
		edgeTo[w] = e;
		pq.update(w, distTo[w]);		//O (log v)
	}
}

