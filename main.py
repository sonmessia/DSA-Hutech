from flask import Flask, request, jsonify
from PIL import Image
import torch
from torchvision import models, transforms

# Tải mô hình ResNet-50
model = models.resnet50(pretrained=True)
model.fc = torch.nn.Linear(model.fc.in_features, 2)
model.load_state_dict(torch.load(r"C:\Users\Duyen\Downloads\resnet50_model.pth", map_location=torch.device('cpu')))
model.eval()

# Chuẩn bị Flask
app = Flask(__name__)

# Hàm tiền xử lý ảnh
def preprocess_image(image_bytes):
    transform = transforms.Compose([
        transforms.Resize((224, 224)),
        transforms.ToTensor(),
        transforms.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225]),
    ])
    image = Image.open(image_bytes).convert("RGB")
    return transform(image).unsqueeze(0)

# Endpoint xử lý ảnh
@app.route('/predict', methods=['POST'])
def predict():
    if 'image' not in request.files:
        return jsonify({'error': 'No image provided'}), 400

    # Lấy ảnh từ yêu cầu
    image_file = request.files['image']
    input_tensor = preprocess_image(image_file)
    
    # Dự đoán bằng mô hình
    with torch.no_grad():
        output = model(input_tensor)
        _, predicted_class = torch.max(output, 1)

    # Áp dụng Softmax
    percent_predictions = torch.nn.functional.softmax(output[0], dim=0)

    # Hiển thị kết quả
    _, indices = torch.topk(percent_predictions, k=5)
    for i, idx in enumerate(indices):
        print(f"{i+1}: Class {idx.item()} ({percent_predictions[idx].item() * 100:.2f}%)")
    return jsonify({'predicted_class': predicted_class.item()})

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)
