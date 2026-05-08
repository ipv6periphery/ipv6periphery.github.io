library(ggplot2)
library(viridis)
library(dplyr)
library(tidyr)


df <- read.csv(file("stdin"), header = FALSE) |>
  transmute(
    prefix = V1,
    x      = as.integer(V2),
    y      = as.integer(V3),
    value  = as.numeric(V4)
  )



n <- 2^12 # 256



groups <- split(df, df$prefix)

for (name in names(groups)) {
  g <- groups[[name]]
  # drop prefix for conserver space
  g$prefix <- NULL
  # g <- g |>
  #   complete(x = 0:(n - 1), y = 0:(n - 1), fill = list(value = NA))

  p <- ggplot(g, aes(x = x, y = y, fill = value)) +
    geom_tile() +
    scale_fill_viridis_c(
      name = NULL,
      trans = "log2",
      na.value = "black",
      limits = c(1, 65536),
      breaks = NULL,
      guide = "none",
      option = "viridis",
    ) +
    coord_fixed(xlim = c(0, n - 1), ylim = c(0, n - 1), expand = FALSE) +
    theme_void() +
    theme(
      legend.position = "none",
      plot.background = element_rect(fill = "#0b0f14", color = NA),
      panel.background = element_rect(fill = "#0b0f14", color = NA),
      panel.border = element_blank(),
      axis.line = element_blank(),
      axis.text = element_blank(),
      axis.ticks = element_blank(),
      axis.title = element_blank()
    )


  ggsave(
    paste0(substr(name, 1, 4), ".png"),
    plot = p,
    width = 32,
    height = 32,
    dpi = 64,
    limitsize = FALSE
  )

  rm(g)
  gc()
  cat("done:", name, "\n")
}


# p <- df |>
#   ggplot(aes(x = x, y = y, fill = value)) +
#   geom_raster() +
#   scale_fill_viridis_c(name = "value", option = "plasma") +
#   coord_fixed() +
#   theme_void() +
#   theme(
#     plot.background = element_rect(fill = "black", color = NA),
#     legend.text     = element_text(color = "white"),
#     legend.title    = element_text(color = "white")
#   )
#
#
# ggsave("hilbert.png", plot = p, width = 8, height = 8, dpi = 1500)
# cat("hilbert.png drawed!\n")
