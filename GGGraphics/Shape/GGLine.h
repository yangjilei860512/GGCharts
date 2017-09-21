//
//  GGLine.h
//  GGCharts
//
//  Created by 黄舜 on 17/9/21.
//  Copyright © 2017年 I really is a farmer. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

struct GGLine {
    CGPoint start;
    CGPoint end;
};
typedef struct GGLine GGLine;

CG_INLINE GGLine
GGLineMake(CGFloat x1, CGFloat y1, CGFloat x2, CGFloat y2)
{
    GGLine line;
    line.start = CGPointMake(x1, y1);
    line.end = CGPointMake(x2, y2);
    return line;
}

CG_INLINE GGLine
GGPointLineMake(CGPoint start, CGPoint end)
{
    GGLine line;
    line.start = start;
    line.end = end;
    return line;
}

CG_INLINE double
GGXCircular(GGLine line)
{
    CGFloat x = line.end.x - line.start.x;
    CGFloat y = line.end.y - line.start.y;
    
    return atan2(y, x);
}

CG_INLINE double
GGYCircular(GGLine line)
{
    CGFloat x = line.end.x - line.start.x;
    CGFloat y = line.end.y - line.start.y;
    
    return atan2(x, y);
}

CG_INLINE CGPoint
GGPerpendicularMake(GGLine line, CGPoint point, CGFloat raidus)
{
    double m_h = raidus * cosf(GGXCircular(line));
    double m_w = raidus * sinf(GGXCircular(line));
    
    CGPoint perpendicular;
    perpendicular.x = point.x - m_w;
    perpendicular.y = point.y + m_h;
    
    return perpendicular;
}

CG_INLINE CGPoint
GGMoveStart(GGLine line, CGFloat move)
{
    CGFloat x = line.start.x + move * cosf(GGXCircular(line));
    CGFloat y = line.start.y + move * sinf(GGXCircular(line));
    return CGPointMake(x, y);
}

CG_INLINE CGPoint
GGMoveEnd(GGLine line, CGFloat move)
{
    CGFloat x = line.end.x + move * cosf(GGXCircular(line));
    CGFloat y = line.end.y + move * sinf(GGXCircular(line));
    return CGPointMake(x, y);
}

CG_INLINE GGLine
GGLineMoveStart(GGLine line, CGFloat move)
{
    CGPoint start = GGMoveStart(line, move);
    return GGPointLineMake(start, line.end);
}

CG_INLINE GGLine
GGLineMoveEnd(GGLine line, CGFloat move)
{
    CGPoint end = GGMoveEnd(line, move);
    return GGPointLineMake(line.start, end);
}

CG_INLINE CGFloat
GGLengthLine(GGLine line)
{
    CGFloat w = line.start.x - line.end.x;
    CGFloat h = line.start.y - line.end.y;
    return sqrtf(h * h + w * w);
}

CG_INLINE CGFloat
GGLineGetWidth(GGLine line)
{
    return fabs(line.end.x - line.start.x);
}

CG_INLINE CGPoint
GGCenterPoint(GGLine line)
{
    return CGPointMake(line.start.x + GGLineGetWidth(line) / 2, line.start.y);
}

CG_INLINE GGLine
GGTopLineRect(CGRect rect)
{
    return GGLineMake(CGRectGetMinX(rect), CGRectGetMinY(rect), CGRectGetMaxX(rect), CGRectGetMinY(rect));
}

CG_INLINE GGLine
GGLeftLineRect(CGRect rect)
{
    return GGLineMake(CGRectGetMinX(rect), CGRectGetMinY(rect), CGRectGetMinX(rect), CGRectGetMaxY(rect));
}

CG_INLINE GGLine
GGBottomLineRect(CGRect rect)
{
    return GGLineMake(CGRectGetMinX(rect), CGRectGetMaxY(rect), CGRectGetMaxX(rect), CGRectGetMaxY(rect));
}

CG_INLINE GGLine
GGRightLineRect(CGRect rect)
{
    return GGLineMake(CGRectGetMaxX(rect), CGRectGetMinY(rect), CGRectGetMaxX(rect), CGRectGetMaxY(rect));
}

CG_INLINE GGLine
GGLineRectForX(CGRect rect, CGFloat x)
{
    x = x > CGRectGetMaxX(rect) ? CGRectGetMaxX(rect) : x;
    x = x < CGRectGetMinX(rect) ? CGRectGetMinX(rect) : x;
    
    return GGLineMake(x, CGRectGetMinY(rect), x, CGRectGetMaxY(rect));
}

CG_INLINE GGLine
GGLineRectForY(CGRect rect, CGFloat y)
{
    y = y > CGRectGetMaxY(rect) ? CGRectGetMaxY(rect) : y;
    y = y < CGRectGetMinY(rect) ? CGRectGetMinY(rect) : y;
    
    return GGLineMake(CGRectGetMinX(rect), y, CGRectGetMaxX(rect), y);
}

NS_ASSUME_NONNULL_END
