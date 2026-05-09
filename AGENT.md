# AGENT.md

## 当前状态
- 站点内容已更新为 `IPv6 Periphery` / `IPv6 Periphery Service`。
- 已移除 `Partners` 和 `External Data Providers` 区块及对应导航入口。
- `Reproducibility` 已改为指向 GitHub 上的 `pruning-as-scanning.sh`。
- `Openly Accessible Service` 仅展示 prefix data，IPv6 具体地址放在 `Registration-First Service`。
- `src/` 已加入 `.gitignore`，不再纳入 Git。
- `README.md` 已精简，只保留简短介绍和后续邮箱说明。

## 当前页面内容
- 新增栏目 `The Space We Known`。
- 该栏目当前引用 `assets/morton_curve_visualization.png`。
- 页面中的图片标签带有本地预览回退：如果本地 `assets/` 文件不存在，会回退到 `http://159.195.149.250/morton_curve_visualization.png`。

## GitHub Pages
- 站点已经切换到 `build_type=workflow`。
- 新增 workflow：`.github/workflows/pages.yml`。
- workflow 会在 `push` 到 `main`、手动触发、以及每日定时任务时执行。
- workflow 会下载 `http://159.195.149.250/morton_curve_visualization.png` 到 `assets/morton_curve_visualization.png`，然后部署到 GitHub Pages。

## 约定
- 本地预览：`python3 -m http.server 8000 --bind 127.0.0.1`
- 远程仓库：`https://github.com/ipv6periphery/ipv6periphery.github.io.git`
- 如需推送时曾使用代理：`https_proxy=http://127.0.0.1:7890/`

## 下一步
- 检查 workflow 首次运行是否成功。
- 确认线上页面能正常显示 Morton curve 图片。
- 如有需要，再继续微调文案或布局。
