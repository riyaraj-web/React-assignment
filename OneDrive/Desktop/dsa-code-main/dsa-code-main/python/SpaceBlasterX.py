import pygame, random, sys
pygame.init()

# --- Screen setup ---
WIDTH, HEIGHT = 800, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("🚀 Space Blaster X")

# --- Colors ---
WHITE = (255, 255, 255)
RED = (255, 0, 0)
YELLOW = (255, 255, 0)
BLACK = (0, 0, 0)

# --- Assets ---
font = pygame.font.SysFont("Arial", 30, bold=True)
clock = pygame.time.Clock()

# --- Classes ---
class Player(pygame.sprite.Sprite):
    def __init__(self):
        super().__init__()
        self.image = pygame.Surface((50, 40))
        self.image.fill(YELLOW)
        self.rect = self.image.get_rect(center=(WIDTH//2, HEIGHT - 50))
        self.speed = 7

    def update(self, keys):
        if keys[pygame.K_LEFT] and self.rect.left > 0:
            self.rect.x -= self.speed
        if keys[pygame.K_RIGHT] and self.rect.right < WIDTH:
            self.rect.x += self.speed

    def shoot(self):
        bullet = Bullet(self.rect.centerx, self.rect.top)
        all_sprites.add(bullet)
        bullets.add(bullet)


class Enemy(pygame.sprite.Sprite):
    def __init__(self):
        super().__init__()
        self.image = pygame.Surface((40, 40))
        self.image.fill(RED)
        self.rect = self.image.get_rect(center=(random.randint(20, WIDTH-20), -40))
        self.speed = random.randint(2, 6)

    def update(self, keys):
        self.rect.y += self.speed
        if self.rect.top > HEIGHT:
            self.kill()


class Bullet(pygame.sprite.Sprite):
    def __init__(self, x, y):
        super().__init__()
        self.image = pygame.Surface((6, 20))
        self.image.fill(WHITE)
        self.rect = self.image.get_rect(center=(x, y))
        self.speed = -10

    def update(self, keys):
        self.rect.y += self.speed
        if self.rect.bottom < 0:
            self.kill()


# --- Groups ---
all_sprites = pygame.sprite.Group()
enemies = pygame.sprite.Group()
bullets = pygame.sprite.Group()

player = Player()
all_sprites.add(player)

score = 0
enemy_spawn_timer = 0
game_over = False

# --- Main Loop ---
while True:
    keys = pygame.key.get_pressed()
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        if not game_over and event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE:
                player.shoot()
        if game_over and event.type == pygame.KEYDOWN and event.key == pygame.K_r:
            # restart
            all_sprites.empty()
            enemies.empty()
            bullets.empty()
            player = Player()
            all_sprites.add(player)
            score = 0
            game_over = False

    if not game_over:
        # Spawn enemies
        enemy_spawn_timer += 1
        if enemy_spawn_timer > 30:
            enemy_spawn_timer = 0
            enemy = Enemy()
            all_sprites.add(enemy)
            enemies.add(enemy)

        # Update sprites
        all_sprites.update(keys)

        # Collision detection
        hits = pygame.sprite.groupcollide(enemies, bullets, True, True)
        score += len(hits) * 10

        if pygame.sprite.spritecollideany(player, enemies):
            game_over = True

    # --- Drawing ---
    screen.fill(BLACK)
    all_sprites.draw(screen)
    score_text = font.render(f"Score: {score}", True, WHITE)
    screen.blit(score_text, (10, 10))

    if game_over:
        over_text = font.render("GAME OVER! Press 'R' to Restart", True, RED)
        screen.blit(over_text, (WIDTH//2 - 200, HEIGHT//2))

    pygame.display.flip()
    clock.tick(60)
