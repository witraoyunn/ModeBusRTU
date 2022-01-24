#include "ModeBusRTU.h"

QString ModeBusRTU::CRC16ForModbus(const QString &hexText)
{
    QByteArray data  = QByteArray::fromHex(hexText.toLocal8Bit());

    quint8 buf;
    quint16 crc16 = 0xFFFF;

    for ( auto i = 0; i < data.size(); ++i )
    {
        buf = data.at( i ) ^ crc16;
        crc16 >>= 8;
        crc16 ^= crc16Table[ buf ];
    }

    //CRCУ������crc16��·�Ϊ�˷��ͱ��ĸ�ʽ����дϰ�ߣ������˸ߵ��ֽ�λ�úʹ�д��ʾ
    quint16 szrst = ((crc16 & 0x00ff) << 8) | (crc16 >> 8);//�����ߵ��ֽ�
    QString rst = QString("%1").arg(szrst , 4, 16, QLatin1Char('0')).toUpper();   //ƴ�ճ�4��16�����ַ�����λ��0
    return  rst;
}

