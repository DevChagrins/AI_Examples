#ifndef _PATH_MAP_H_
#define _PATH_MAP_H_

#include <vector>

class PathMap
{
public:
	PathMap();
	~PathMap();

	bool LoadMap(const char* fileName);
	void RenderMap();
private:

	void AddNode(PathNode* newNode);

	int width;
	int height;
	PathNode** nodeRenderMap;

	std::vector<PathNode*> map;
	PathNode* start;
	PathNode* end;
};

struct PathNode
{
public:
	PathNode() = default;
	~PathNode();

	int weight;
	int x, y;
	int tileType;

	PathNode* neighbors[8];
};

#endif // _PATH_MAP_H_