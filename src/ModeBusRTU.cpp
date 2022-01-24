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

    //CRC校验结果在crc16里，下方为了发送报文格式的书写习惯，交换了高地字节位置和大写显示
    quint16 szrst = ((crc16 & 0x00ff) << 8) | (crc16 >> 8);//交换高低字节
    QString rst = QString("%1").arg(szrst , 4, 16, QLatin1Char('0')).toUpper();   //拼凑成4个16进制字符，空位补0
    return  rst;
}

