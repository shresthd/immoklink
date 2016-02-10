<?php
/**
 * @file
 * Layout template.
 */
?>
<div class="page">
    <header>
      <?php print $content['top']; ?>
    </header>
    <nav>
      <?php print $content['nav']; ?>
    </nav>

    <div class="clear-left"></div>

    <article>
      <?php print $content['content']; ?>
    </article>
</div>