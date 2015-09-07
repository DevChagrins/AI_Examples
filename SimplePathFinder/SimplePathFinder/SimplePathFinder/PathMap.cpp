#include "PathMap.h"
#include "IOColor.h"
using namespace IOCOLOR;

PathMap::PathMap() : start(nullptr), end(nullptr),
	width(0), height(0)
{
	map.clear();
	nodeRenderMap = nullptr;
}


PathMap::~PathMap()
{
	map.clear();
	if (nodeRenderMap != nullptr)
	{
		for (int y = 0; y < height; y++)
		{
			if (nodeRenderMap[y] != nullptr)
			{
				delete[] nodeRenderMap;
			}
		}
	}

	start = nullptr;
	end = nullptr;
}

bool PathMap::LoadMap(const char* fileName)
{
	bool didLoad = false;

	return didLoad;
}

void PathMap::RenderMap()
{
	if (nodeRenderMap != nullptr)
	{
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				if (nodeRenderMap[y][x].tileType == 1)
				{
					cout << GREEN;
				}
				else if (nodeRenderMap[y][x].tileType == 2)
				{
					cout << RED;
				}
				else
				{
					cout << WHITE;
				}

				cout << nodeRenderMap[y][x].weight;
			}
		}
	}
}


void PathMap::AddNode(PathNode* newNode)
{
	if (newNode != nullptr)
	{
		map.push_back(newNode);

		// Start tile
		if (newNode->tileType == 1)
		{
			if (start == nullptr)
			{
				start = newNode;
			}
		}
		// End tile
		else if (newNode->tileType == 2)
		{
			if (end == nullptr)
			{
				end = newNode;
			}
		}
	}
}
