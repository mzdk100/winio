#include "msgbox.hpp"

std::unique_ptr<QMessageBox> new_message_box(QWidget *parent) {
    auto box = std::make_unique<QMessageBox>(parent);
    box->setWindowModality(Qt::WindowModal);
    return box;
}

void message_box_connect_finished(QMessageBox &b,
                                  callback_fn_t<void(int)> callback,
                                  std::uint8_t const *data) {
    QObject::connect(&b, &QMessageBox::finished,
                     [callback, data](int result) { callback(data, result); });
}

QPushButton *message_box_add_button(QMessageBox &b, rust::Str text) {
    return b.addButton(QString::fromUtf8(text.data(), text.size()),
                       QMessageBox::AcceptRole);
}
