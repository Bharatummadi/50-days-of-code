class Solution(object):
	def findCheapestPrice(self, n, flights, src, dst, K):
		graph = collections.defaultdict(list)
		pq = []

		for u, v, w in flights: graph[u].append((w, v))

		heapq.heappush(pq, (0, K+1, src))
		while pq:
			price, stops, city = heapq.heappop(pq)

			if city is dst: return price
			if stops>0:
				for price_to_nei, nei in graph[city]:
					heapq.heappush(pq, (price+price_to_nei, stops-1, nei))
		return -1
