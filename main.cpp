#include "pch.h"

#include "PacketList.h"

#include "CaptureEngine.h"
#include "AnalyzeEngine.h"
#include "SortEngine.h"
#include "OutputEngine.h"



int main()
{
	PacketList * pktList = new PacketList();

	CaptureEngine  * CE = new CaptureEngine();
	
	AnalyzeEngine  * AE = new AnalyzeEngine();

	SortEngine	*  SE = new SortEngine(pktList);
	
	OutputEngine * OE = new OutputEngine(pktList);
	
	
	while(1)
	{		
		RawData * rawdata = CE->capture();

		AE->analyze(rawdata,SE);
		
		OE->printScreen();
		
	}

}