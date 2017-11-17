#include "video_surveillance_screen.h"
#include <QMouseEvent>

QString VideoSurveillanceScreen::getRoomName(int index) const
{
    switch (index)
    {
        case 0:
            return "Main Entrance";

        case 1:
            return "Living room 1";

        case 2:
            return "Living room 2";

        case 3:
            return "Parents Bedroom";

        case 4:
            return "Bob's Bedroom";

        case 5:
            return "Alice's Bedroom";

        case 6:
            return "Hall";

        case 7:
            return "Kitchen";

        case 8:
            return "Study";
    }

    return "";
}

VideoSurveillanceScreen::VideoSurveillanceScreen(QWidget* parent) : BaseContentScreen(parent)
{
    m_background_widget = new PlaceholderWidget(this, m_background_widget_size, Qt::green, "", 1);

    for (int i = 0; i < m_column_count * m_row_count; i++)
    {
        VideoWidget* video_widget = new VideoWidget(this, m_video_widget_size, getRoomName(i));
        m_video_widget_vector.push_back(video_widget);
    }

    setupLayout();
}

void VideoSurveillanceScreen::setupLayout()
{
    BaseContentScreen::setupLayout();

    m_background_widget->resize(m_background_widget_size.width() * m_width_scale, m_background_widget_size.height() * m_height_scale);
    m_background_widget->move(m_background_widget_pos.x() * m_width_scale, m_background_widget_pos.y() * m_height_scale);

    if (m_video_selected == true)
    {
        for (int i = 0; i < m_video_widget_vector.size(); i++)
        {
            if (i == m_selected_video_index)
            {
                m_video_widget_vector[i]->resize(m_background_widget_size.width() * m_width_scale, m_background_widget_size.height() * m_height_scale);
                m_video_widget_vector[i]->move(0, 0);
            }
            else
            {
                m_video_widget_vector[i]->hide();
            }
        }
    }
    else
    {
        QSize video_widget_size(m_video_widget_size.width() * m_width_scale, m_video_widget_size.height() * m_height_scale);
        for (auto video_widget: m_video_widget_vector)
        {
            video_widget->resize(video_widget_size);
            video_widget->show();
        }

        for (int i = 0; i < m_video_widget_vector.size(); i++)
        {
            int row = i / m_column_count;
            int column = i % m_column_count;

            qreal x = (m_video_widget_size.width() + m_horizontal_space) * column * m_width_scale;
            qreal y = (m_video_widget_size.height() + m_vertical_space) * row * m_height_scale;

            m_video_widget_vector[i]->move(x, y);
        }
    }
}

void VideoSurveillanceScreen::mouseReleaseEvent(QMouseEvent* event)
{
    if (m_video_selected == true)
    {
        m_video_selected = false;
    }
    else
    {
        qreal column_width = qreal(width()) / m_column_count;
        qreal row_height = qreal(height()) / m_row_count;

        int row = event->y() / row_height;
        int column = event->x() / column_width;

        m_video_selected = true;
        m_selected_video_index = row * m_column_count + column;
    }

    setupLayout();
}
