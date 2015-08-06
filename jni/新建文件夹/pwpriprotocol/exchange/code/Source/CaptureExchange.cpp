#include "../Include/ExchangeAL/Exchange.h"
#include "../Include/ExchangeAL/CaptureExchange.h"

// ȫ����������
template<> void exchangeTable<CAPTURE_PANOATTR>(CConfigTable &table, CAPTURE_PANOATTR &config, int state)
{
	CKeyExchange exchanger;
	
	exchanger.setState(state);
	
	exchanger.exchange(table, "CenterX", config.CenterX);
	exchanger.exchange(table, "CenterY", config.CenterY);
	exchanger.exchange(table, "Radius", config.Radius);
	exchanger.exchange(table, "PanoMask", config.PanoMask);
	exchanger.exchange(table, "PanoTilt", config.PanoTilt);
	for(int i = 0; i < 6; i++)
	{
		exchanger.exchange(table["ElliPara"], i, config.ElliPara[i]);
	}
}

// ����ȫ����������
template<> void exchangeTable<CapturePanoAttrAll>(CConfigTable &table, CapturePanoAttrAll &configAll, int state)
{
	for(int i = 0; i < N_SYS_CH; i++)
	{
		if(table[i] == Json::nullValue && state == CKeyExchange::ES_LOADING)
		{
			continue;
		}
		exchangeTable(table[i], configAll.vCapturePanoAll[i], state);
	}
}

// ����ȫ����������V2
template<> void exchangeTableV2<CapturePanoAttrAll>(CConfigTable &table, CapturePanoAttrAll &configAll, int state, int nSize)
{
	for(int i = 0; i < nSize; i++)
	{
		if(table[i] == Json::nullValue && state == CKeyExchange::ES_LOADING)
		{
			continue;
		}
		exchangeTable(table[i], configAll.vCapturePanoAll[i], state);
	}
}