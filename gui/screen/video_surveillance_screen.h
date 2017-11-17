#ifndef VIDEO_SURVEILLANCE_SCREEN_H
#define VIDEO_SURVEILLANCE_SCREEN_H

#include "base_content_screen.h"
#include "gui/widget/video_widget.h"
#include "gui/widget/placeholder_widget.h"

class VideoSurveillanceScreen : public BaseContentScreen
{
    Q_OBJECT

    PlaceholderWidget* m_background_widget{nullptr};
    QVector<VideoWidget*> m_video_widget_vector;

    QSize m_background_widget_size{730, 440};
    QSize m_video_widget_size{240, 144};

    QPoint m_background_widget_pos{0, 0};

    int m_horizontal_space{5};
    int m_vertical_space{4};

    int m_row_count{3};
    int m_column_count{3};

    QString getRoomName(int index) const;

    int m_selected_video_index{0};
    bool m_video_selected{false};

public:
    explicit VideoSurveillanceScreen(QWidget* parent);

protected:
    void setupLayout();
    void mouseReleaseEvent(QMouseEvent* event);
};

#endif
