#include "GraphRepository.h"
#include "engine/util/Log.h"


GraphRepository::GraphRepository()
{
}


GraphRepository::~GraphRepository()
{
}

Graph* GraphRepository::getGraph(char* map)
{
	Graph* graph	= new Graph();
	int map_id		= 1; //Default 1
	
	if(map == "./res/maps/level1.tmx")
	{
		//map_id = 1; Is default
	}
	else if(map == "./res/maps/level2.tmx")
	{
		map_id = 2;
	} 
	else if(map == "./res/maps/level3.tmx")
	{
		map_id = 3;
	}

	generateGraph(graph, map_id);

	return graph;
}


void GraphRepository::generateGraph(Graph* graph, int map_id)
{
	if(map_id == 1) //Graph for level1
	{
		//Create vertices

		//--------Op de grond-------------
		auto vertex1 = new Vertex(40, 680);
		graph->addVertex(vertex1);
		auto vertex2 = new Vertex(100, 680);
		graph->addVertex(vertex2);
		auto vertex3 = new Vertex(160, 680);
		graph->addVertex(vertex3);
		auto vertex4 = new Vertex(220, 680);
		graph->addVertex(vertex4);
		auto vertex5 = new Vertex(280, 680);
		graph->addVertex(vertex5);
		auto vertex6 = new Vertex(340, 680);
		graph->addVertex(vertex6);
		auto vertex7 = new Vertex(400, 680);
		graph->addVertex(vertex7);
		auto vertex8 = new Vertex(460, 680);
		graph->addVertex(vertex8);
		auto vertex9 = new Vertex(520, 680);
		graph->addVertex(vertex9);
		auto vertex10 = new Vertex(580, 680);
		graph->addVertex(vertex10);
		auto vertex11 = new Vertex(640, 680);
		graph->addVertex(vertex11);
		auto vertex12 = new Vertex(700, 680);
		graph->addVertex(vertex12);
		auto vertex13 = new Vertex(760, 680);
		graph->addVertex(vertex13);
		auto vertex14 = new Vertex(820, 680);
		graph->addVertex(vertex14);
		auto vertex15 = new Vertex(880, 680);
		graph->addVertex(vertex15);
		auto vertex16 = new Vertex(940, 680);
		graph->addVertex(vertex16);
		auto vertex17 = new Vertex(1000, 680);
		graph->addVertex(vertex17);
		auto vertex18 = new Vertex(1060, 680);
		graph->addVertex(vertex18);
		auto vertex19 = new Vertex(1120, 680);
		graph->addVertex(vertex19);
		auto vertex20 = new Vertex(1180, 680);
		graph->addVertex(vertex20);

		//--------Op de blokjes van de grond--
		auto vertex21 = new Vertex(320, 640);
		graph->addVertex(vertex21);
		auto vertex22 = new Vertex(620, 640);
		graph->addVertex(vertex22);
		auto vertex23 = new Vertex(1080, 640);
		graph->addVertex(vertex23);

		//--------onderste laag platformen----
		auto vertex24 = new Vertex(40, 560);
		graph->addVertex(vertex24);
		auto vertex25 = new Vertex(180, 560);
		graph->addVertex(vertex25);
		auto vertex26 = new Vertex(240, 560);
		graph->addVertex(vertex26);
		auto vertex27 = new Vertex(480, 560);
		graph->addVertex(vertex27);
		auto vertex28 = new Vertex(720, 560);
		graph->addVertex(vertex28);
		auto vertex29 = new Vertex(980, 560);
		graph->addVertex(vertex29);
		auto vertex30 = new Vertex(1040, 560);
		graph->addVertex(vertex30);
		auto vertex31 = new Vertex(1180, 560);
		graph->addVertex(vertex31);

		//--------tussen laag 1 en 2 platformen----
		auto vertex32 = new Vertex(700, 500);
		graph->addVertex(vertex32);

		//--------2e laag platformen----
		auto vertex33 = new Vertex(60, 460);
		graph->addVertex(vertex33);
		auto vertex34 = new Vertex(240, 460);
		graph->addVertex(vertex34);
		auto vertex35 = new Vertex(400, 440);
		graph->addVertex(vertex35);
		auto vertex36 = new Vertex(820, 440);
		graph->addVertex(vertex36);
		auto vertex37 = new Vertex(1020, 460);
		graph->addVertex(vertex37);
		auto vertex38 = new Vertex(1160, 460);
		graph->addVertex(vertex38);

		//--------Laag waar de bal op valt bij spawn
		auto vertex39 = new Vertex(260, 340);
		graph->addVertex(vertex39);
		auto vertex40 = new Vertex(520, 340);
		graph->addVertex(vertex40);
		auto vertex41 = new Vertex(610, 340);
		graph->addVertex(vertex41);
		auto vertex42 = new Vertex(640, 340);
		graph->addVertex(vertex42);
		auto vertex43 = new Vertex(660, 340);
		graph->addVertex(vertex43);
		auto vertex44 = new Vertex(680, 340);
		graph->addVertex(vertex44);
		auto vertex45 = new Vertex(940, 340);
		graph->addVertex(vertex45);

		//Laag van goals en spawn van spelers
		auto vertex46 = new Vertex(80, 220);
		graph->addVertex(vertex46);
		auto vertex47 = new Vertex(400, 220);
		graph->addVertex(vertex47);
		auto vertex48 = new Vertex(460, 220);
		graph->addVertex(vertex48);
		auto vertex49 = new Vertex(760, 220);
		graph->addVertex(vertex49);
		auto vertex50 = new Vertex(820, 220);
		graph->addVertex(vertex50);
		auto vertex51 = new Vertex(1220, 220);
		graph->addVertex(vertex51);

		//Laag boven de goals
		auto vertex52 = new Vertex(120, 100);
		graph->addVertex(vertex52);
		auto vertex53 = new Vertex(180, 100);
		graph->addVertex(vertex53);
		auto vertex54 = new Vertex(260, 60);
		graph->addVertex(vertex54);
		auto vertex55 = new Vertex(340, 120);
		graph->addVertex(vertex55);
		auto vertex56 = new Vertex(400, 120);
		graph->addVertex(vertex56);
		auto vertex57 = new Vertex(460, 80);
		graph->addVertex(vertex57);
		auto vertex58 = new Vertex(560, 120);
		graph->addVertex(vertex58);
		auto vertex59 = new Vertex(580, 120);
		graph->addVertex(vertex59);
		auto vertex60 = new Vertex(640, 120);
		graph->addVertex(vertex60);
		auto vertex61 = new Vertex(700, 120);
		graph->addVertex(vertex61);
		auto vertex62 = new Vertex(760, 80);
		graph->addVertex(vertex62);
		auto vertex63 = new Vertex(780, 120);
		graph->addVertex(vertex63);
		auto vertex64 = new Vertex(880, 120);
		graph->addVertex(vertex64);
		auto vertex65 = new Vertex(940, 60);
		graph->addVertex(vertex65);
		auto vertex66 = new Vertex(1000, 100);
		graph->addVertex(vertex66);
		auto vertex67 = new Vertex(1060, 100);
		graph->addVertex(vertex67);

		//Edges op de grond
		graph->addEdge(new Edge(vertex1, vertex2));
		graph->addEdge(new Edge(vertex2, vertex3));
		graph->addEdge(new Edge(vertex3, vertex4));
		graph->addEdge(new Edge(vertex4, vertex5));
		graph->addEdge(new Edge(vertex5, vertex21));
		graph->addEdge(new Edge(vertex21, vertex6));
		graph->addEdge(new Edge(vertex6, vertex7));
		graph->addEdge(new Edge(vertex7, vertex8));
		graph->addEdge(new Edge(vertex8, vertex9));
		graph->addEdge(new Edge(vertex9, vertex10));
		graph->addEdge(new Edge(vertex10, vertex22));
		graph->addEdge(new Edge(vertex22, vertex11));
		graph->addEdge(new Edge(vertex11, vertex12));
		graph->addEdge(new Edge(vertex12, vertex13));
		graph->addEdge(new Edge(vertex14, vertex15));
		graph->addEdge(new Edge(vertex15, vertex23));
		graph->addEdge(new Edge(vertex23, vertex16));
		graph->addEdge(new Edge(vertex16, vertex17));
		graph->addEdge(new Edge(vertex17, vertex18));
		graph->addEdge(new Edge(vertex18, vertex19));
		graph->addEdge(new Edge(vertex19, vertex20));

		graph->addEdge(new Edge(vertex2, vertex24));
		graph->addEdge(new Edge(vertex3, vertex25));
		graph->addEdge(new Edge(vertex5, vertex26));
		graph->addEdge(new Edge(vertex21, vertex26));
		graph->addEdge(new Edge(vertex21, vertex27));
		graph->addEdge(new Edge(vertex6, vertex27));
		graph->addEdge(new Edge(vertex10, vertex27));
		graph->addEdge(new Edge(vertex22, vertex27));
		graph->addEdge(new Edge(vertex22, vertex28));
		graph->addEdge(new Edge(vertex11, vertex28));
		graph->addEdge(new Edge(vertex15, vertex28));
		graph->addEdge(new Edge(vertex23, vertex28));
		graph->addEdge(new Edge(vertex23, vertex29));
		graph->addEdge(new Edge(vertex16, vertex29));
		graph->addEdge(new Edge(vertex18, vertex30));
		graph->addEdge(new Edge(vertex19, vertex31));

		graph->addEdge(new Edge(vertex25, vertex33));
		graph->addEdge(new Edge(vertex25, vertex34));
		graph->addEdge(new Edge(vertex26, vertex34));
		graph->addEdge(new Edge(vertex26, vertex35));

		graph->addEdge(new Edge(vertex27, vertex35));
		graph->addEdge(new Edge(vertex27, vertex32));

		graph->addEdge(new Edge(vertex28, vertex32));
		graph->addEdge(new Edge(vertex28, vertex36));

		graph->addEdge(new Edge(vertex29, vertex36));
		graph->addEdge(new Edge(vertex29, vertex37));
		graph->addEdge(new Edge(vertex30, vertex37));
		graph->addEdge(new Edge(vertex30, vertex38));

		graph->addEdge(new Edge(vertex34, vertex39));
		graph->addEdge(new Edge(vertex35, vertex39));
		graph->addEdge(new Edge(vertex36, vertex45));
		graph->addEdge(new Edge(vertex37, vertex45));

		graph->addEdge(new Edge(vertex39, vertex47));
		graph->addEdge(new Edge(vertex45, vertex50));

		graph->addEdge(new Edge(vertex47, vertex56));
		graph->addEdge(new Edge(vertex48, vertex56));
		graph->addEdge(new Edge(vertex49, vertex63));
		graph->addEdge(new Edge(vertex50, vertex63));

		graph->addEdge(new Edge(vertex56, vertex57));
		graph->addEdge(new Edge(vertex63, vertex62));

		graph->addEdge(new Edge(vertex24, vertex25));
		graph->addEdge(new Edge(vertex31, vertex30));
		graph->addEdge(new Edge(vertex33, vertex34));
		graph->addEdge(new Edge(vertex37, vertex38));

		graph->addEdge(new Edge(vertex47, vertex48));
		graph->addEdge(new Edge(vertex48, vertex40));
		graph->addEdge(new Edge(vertex40, vertex41));
		graph->addEdge(new Edge(vertex41, vertex42));
		graph->addEdge(new Edge(vertex42, vertex43));
		graph->addEdge(new Edge(vertex43, vertex44));
		graph->addEdge(new Edge(vertex44, vertex49));
		graph->addEdge(new Edge(vertex49, vertex50));

		graph->addEdge(new Edge(vertex41, vertex48));
		graph->addEdge(new Edge(vertex43, vertex49));

		graph->addEdge(new Edge(vertex46, vertex52));
		graph->addEdge(new Edge(vertex52, vertex53));
		graph->addEdge(new Edge(vertex53, vertex54));
		graph->addEdge(new Edge(vertex54, vertex55));
		graph->addEdge(new Edge(vertex55, vertex56));
		graph->addEdge(new Edge(vertex56, vertex57));
		graph->addEdge(new Edge(vertex57, vertex58));
		graph->addEdge(new Edge(vertex58, vertex59));
		graph->addEdge(new Edge(vertex59, vertex60));
		graph->addEdge(new Edge(vertex60, vertex61));
		graph->addEdge(new Edge(vertex61, vertex62));
		graph->addEdge(new Edge(vertex62, vertex63));
		graph->addEdge(new Edge(vertex63, vertex64));
		graph->addEdge(new Edge(vertex64, vertex65));
		graph->addEdge(new Edge(vertex65, vertex66));
		graph->addEdge(new Edge(vertex66, vertex67));
		graph->addEdge(new Edge(vertex67, vertex51));

	} 
	else if(map_id == 2) //Graph for level2
	{
		
	} 
	else if(map_id == 3) //Graph for level3
	{
		
	}
}
