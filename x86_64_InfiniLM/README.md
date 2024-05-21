# InfiniLM

## 现有测例来源

- `xtask`

  ```sh
  $ cargo build --package xtask --release
  ```

- `config.json`，`tokenizer.model`：`https://huggingface.co/TinyLlama/TinyLlama-1.1B-Chat-v1.0`上文件 cast 为 F16 精度

## 需要补齐

由于`github`大小限制，测试模型无法直接上传，因此需要手动将其移动到本文件夹下。

即将`model.safetensors`文件从转化后的模型中移动到本目录下的`TinyLlama_F16`中

## 测例打包方式

1. 检查`build_img.sh`是否修改生成的镜像大小为足够的大小（至少为 2.5G），如没有可以修改为

   ```sh
   $ dd if=/dev/zero of=disk.img bs=4M count=1024 # 4G 大小
   ```

   