#include "QtGraphicsComponent.h"

namespace Frog
{
    /*!
     * \brief Устанавливает контекст, в котором происходит отображение графики
     * \param renderDevice Контекст
     */
    void QtGraphicsComponent::setRenderDevice(QtWindowComponent *renderDevice)
    {
        this->renderDevice = renderDevice;
    }

    void QtGraphicsComponent::clear()
    {
        QPainter painter(renderDevice);
        painter.fillRect(0,
                         0,
                         renderDevice->size().width(),
                         renderDevice->size().height(),
                         Qt::black);
    }

    void QtGraphicsComponent::drawEllipse(GraphicsComponent::DrawMode mode, int x, int y, int w, int h)
    {
        QPainter painter(renderDevice);
        if (mode == DrawMode::Fill)
            painter.setBrush(QBrush(color));

        painter.setPen(color);
        painter.drawEllipse(x + FG::cameraOffsetX, y + FG::cameraOffsetY, w, h);
    }

    void QtGraphicsComponent::drawQuad(GraphicsComponent::DrawMode mode, int x, int y, int w, int h)
    {
        QPainter painter(renderDevice);
        if (mode == DrawMode::Fill)
            painter.setBrush(QBrush(color));

        painter.setPen(color);
        painter.drawRect(x + FG::cameraOffsetX, y + FG::cameraOffsetY, w, h);
    }

    void QtGraphicsComponent::drawLine(int x1, int y1, int x2, int y2)
    {
        QPainter painter(renderDevice);
        painter.setPen(color);
        painter.drawLine(x1 + FG::cameraOffsetX, y1 + FG::cameraOffsetY, x2, y2);
    }

    void QtGraphicsComponent::drawText(const char *text, int x, int y)
    {
        QPainter painter(renderDevice);
        painter.setPen(color);
        painter.drawText(x + FG::cameraOffsetX, y + FG::cameraOffsetY, text);
    }

    void QtGraphicsComponent::drawImage(INativeImage *image, int x, int y)
    {
        image->nativeDraw(x + FG::cameraOffsetX, y + FG::cameraOffsetY);
    }

    void QtGraphicsComponent::drawImage(INativeImage *image, int x, int y, int w, int h)
    {
        image->nativeDraw(x + FG::cameraOffsetX, y + FG::cameraOffsetY, w, h);
    }

    void QtGraphicsComponent::drawImage(INativeImage *image, int x, int y, int sx, int sy, int sw, int sh)
    {
        image->nativeDraw(x + FG::cameraOffsetX, y + FG::cameraOffsetY, sx, sy, sw, sh);
    }

    /*!
     * \brief Рисует изображение платформы Qt в точке (x,y) с прозрачностью alpha
     * \param pixmap Изображение
     * \param x Координата X
     * \param y Координата Y
     * \param alpha Альфа-канал
     */
    void QtGraphicsComponent::drawPixmap(QPixmap &pixmap, int x, int y, float alpha)
    {
        QPainter painter(renderDevice);
        painter.setOpacity(alpha);
        painter.drawPixmap(x, y, pixmap);
    }

    /*!
     * \brief Рисует изображение платформы Qt в точке (x,y) с прозрачностью alpha, заданным размером
     * \param pixmap Изображение
     * \param x Координата X
     * \param y Координата Y
     * \param w Ширина
     * \param h Высота
     * \param alpha Альфа-канал
     */
    void QtGraphicsComponent::drawPixmap(QPixmap &pixmap, int x, int y, int w, int h, float alpha)
    {
        QPainter painter(renderDevice);
        painter.setOpacity(alpha);
        painter.drawPixmap(x, y, w, h, pixmap);
    }

    /*!
     * \brief Рисует фрагмент изображения платформы Qt в точке (x,y) с прозрачностью alpha
     * \param pixmap Изображение
     * \param x Координата X
     * \param y Координата Y
     * \param sx Координата X фрагмента
     * \param sy Координата Y фрагмента
     * \param sw Ширина фрагмента
     * \param sh Высота фрагмента
     * \param alpha Альфа-канал
     */
    void QtGraphicsComponent::drawPixmap(QPixmap &pixmap, int x, int y, int sx, int sy, int sw, int sh, float alpha)
    {
        QPainter painter(renderDevice);
        painter.setOpacity(alpha);
        painter.drawPixmap(x, y, pixmap, sx, sy, sw, sh);
    }

    void QtGraphicsComponent::setColor(Color color)
    {
        auto representation = color.getRepresentation();

        int r = (representation >> 16) & 0x000000ff;
        int g = (representation >> 8) & 0x000000ff;
        int b = representation & 0x000000ff;
        int a = (representation >> 24) & 0x000000ff;

        this->color = QColor(r, g, b, a);
    }  
} // Frog
