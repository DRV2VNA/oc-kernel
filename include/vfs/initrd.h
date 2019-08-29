#pragma once

#include <lib/stdtypes.h>
#include <boot/multiboot.h>

#define INITRD_MAX_FILES 64
#define INITRD_MAGIC 0xBF

extern struct initrd_node_t
{
  unsigned char magic; /* magic number */
  char name[64];       /* file name */
  unsigned int offset; /* file base */
  unsigned int length; /* file length */
};

extern struct initrd_fs_t
{
  int count;                                   /* files count */
  struct initrd_node_t node[INITRD_MAX_FILES]; /* files headers */
};

/*
 * Api
 */
extern void initrd_autorun(struct mod_addr_t *mods_addr, int mods_count, char *name);
extern void initrd_exec(char *name, size_t base);
